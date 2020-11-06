#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxSize 1000
 
typedef struct {
	int weight;
	int parent;
	int lchild;
	int rchild;
}HFTreeNode;
typedef HFTreeNode HuffmanTree;

struct CodeNode{ 
     char ch; 	                         //存储字符
     char bits[MaxSize]; 	          //存放编码位串
};
typedef struct CodeNode CodeNode;
typedef CodeNode HuffmanCode;  

int n;
int m;
HuffmanTree T[MaxSize];
HuffmanCode H[MaxSize];

void sum(){                                 //录入叶子数 
	printf("请输入叶子数：\n");         
	scanf("%d",&n);	
}


void SelectMin(int g,int &s1,int &s2)                             //确定权值最小的两个根结点 
{ 
     int j, k, m, i; 
     for (k=1; k<=g; k++){                                      //找到parent为空的子树
          if (T[k].parent==0){
               s1=k;
		     break;
          }
     }                           
     for (j=1; j<=g; j++){                                      //找到parent为空的权值最小子树
          if((T[j].weight<=T[s1].weight) && (T[j].parent==0))  
		     s1=j;         
     }  
     for (m=1; m<=g; m++){                                      //找到parent为空的不同于s1子树
	     if((T[m].parent==0) && (m!=s1)){
		     s2=m; 
			break;
          }
     }  
     for (i=1; i<=g; i++){                                      //找到parent为空的不同于s1的权值次小子树
          if((T[i].weight<=T[s2].weight) && (T[i].parent==0) && (i!=s1)){ 
		     s2=i;
          }
               
     } 
}

void CreateHuffmanTree(){ 
     int i, p1, p2;     
	if (n<1){
	exit(0);
	}
	m=2*n;  	                             
     for (i=1; i<m; i++){
          T[i].parent=0; 
          T[i].lchild=0;
          T[i].rchild=0;
	     T[i].weight=0;
     }
	printf("请依次输入叶子结点的权值：\n");     
	for(i=1;i<=n;i++){                       //读入叶子结点权值
	     scanf("%d", &T[i].weight);  
     }
     printf("请依次输入叶子结点的权值所对应的字符：\n");
	for(i=0;i<n;i++){                        //读入叶子符号 
		getchar();
		H[i].ch=getchar();
	}
	printf("叶子符号与其对应的权值为：\n"); 
	for(i=0;i<n;i++){
		printf("%c\t",H[i].ch);
	}
	printf("\n");
	for(i=1;i<=n;i++){
		printf("%d\t",T[i].weight);
	}
	printf("\n");                                        
	for(i=n+1;i<m;i++)  
     {  
          SelectMin(i-1,p1,p2);             //选择当前权值最小的两个根结点 
          T[p1].parent=T[p2].parent=i;  
          T[i].lchild=p1;                   //最小权的根结点是新结点的左孩子 
          T[i].rchild=p2;                   //次小权的根结点是新结点的右孩子 
          T[i].weight=T[p1].weight+T[p2].weight; 
     } 
}

void out1(){
	int i;
	printf("每个结点的权值、双亲、左孩子和右孩子分别为：\n");
	printf("number:");
	for(i=1;i<m;i++){
	     printf("%d\t",i);
	}
	printf("\n");
	printf("Weight:");
	for(i=1;i<m;i++){
	     printf("%d\t",T[i].weight);
	}
	printf("\n");
	printf("parent:");
	for(i=1;i<m;i++){
	     printf("%d\t",T[i].parent);
	}
	printf("\n");
	printf("lchild:");
	for(i=1;i<m;i++){
	     printf("%d\t",T[i].lchild);
	}
	printf("\n");
	printf("rchild:");
	for(i=1;i<m;i++){
	     printf("%d\t",T[i].rchild);
	}
	printf("\n");
} 

void CharSetHuffmanEncoding(){                      //据哈夫曼树T求哈夫曼编码表H              
     int c,p,i;                                     //c和p分别表示T中孩子和双亲的位置
	char cd[n+1];                                  //临时存放编码     
     int start;                                     //表示编码在cd中的起始位置  	                                   
     cd[n]='\0'; 	                                //编码结束符     
     for(i=0;i<n;i++){ 	                           //依次求叶子T[i]的编码            
          start=n; 	                                //编码起始位置的初值 
          c=i+1;
	     p=T[c].parent;	 	                           //从叶子T[i]开始上溯 
          while(p>0){
              if(T[p].lchild==c){
		         cd[--start]='0';
	         } 
              else{
		         cd[--start]='1';
		    }            
              c=p; 
		    p=T[c].parent;                        //继续上溯 
          } 
          strcpy(H[i].bits, &cd[start]);            //复制编码位串                                          
     }
	  	       
} 

void CharSetHuffmanDecoding(){    
     int j=0;
	int g; 
	int p=2*n-1;                                      //从根结点开始 
     int i=0;
	char cs[n+1];
	printf("请输入赫夫曼编码长度：\n");
	scanf("%d",&g); 
	printf("请依次输入赫夫曼编码：\n");
	for(j=0;j<g;j++){
		cs[j]=getchar();getchar();
	}
	cs[m]='\0'; 
     while(cs[i]!='\0'){ 	                         //当要解码的字符串没有结束时 
          while((T[p].lchild != 0 && T[p].rchild != 0) && cs[i] !='\0'){ //当还没有达到哈夫曼叶子结点且要解码的字符串没有结束时 
              if (cs[i]=='0'){ 
                   p=T[p].lchild; 
              }                                        //如果是0,则叶子在左子树               
              else{
		         p=T[p].rchild; 
              }                                        //如果是1,则叶子在右子树               
	         i++;  
          } 
          if(T[p].lchild == 0 && T[p].rchild == 0){    //如果达到叶子时 
              printf("此赫夫曼编码所对应字符为：\n"); 
              printf("%c\n", H[p-1].ch);  
		    p=2*n-1;  
	     } 
          else{                                        //如果编号p的结点不是叶子,则编码有错 
              printf("\n解码有错。\n");  
		    exit(0);  
          }
     }
     printf("\n"); 
}


int main(){
	printf("先进行赫夫曼树的实验。\n");
	sum();
	CreateHuffmanTree();
	out1();
	CharSetHuffmanEncoding();	
	return 0;
}