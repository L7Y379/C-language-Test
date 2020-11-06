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
int cs[26]={0};
char c1[MaxSize]; 
HuffmanTree T[53];
HuffmanCode H1[27];
HuffmanCode H2[27];
int sum(){                              //读文本 返回出现字母的个数
	char c;
	int num=0,i=0;
	printf("请输入文本:\n");
	gets(c1);
	while(c1[i]!='\0'){ 
		c=c1[i];
		if(c!=' '){
		    if(c<='Z')cs[c-65]++;
		    else cs[c-97]++;
		}
		i++;
	}
	for(i=0;i<26;i++)
	     if(cs[i]!=0)
	         num++;
	return num;
}

void SelectMin(int g,int &s1,int &s2)                            //确定权值最小的两个根结点 
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
	int i,p1,p2,m;
	int j=0;
	if(n<1){
	     printf("没有输入文本！");
		exit(0);
	}
	m=2*n;
	for(i=1;i<m;i++){
		T[i].parent=0;
		T[i].lchild=0;
		T[i].rchild=0;
		T[i].weight=0;
	} 
    for(i=1;i<=n;i++){
    	     while(cs[j]==0)
              j++;
    	     T[i].weight=cs[j];
    	     j++;
    } 
	
	for(i=n+1;i<m;i++){
		SelectMin(i-1,p1,p2);
		T[p1].parent=i;
		T[p2].parent=i;
		T[i].lchild=p1;
		T[i].rchild=p2;
		T[i].weight=T[p1].weight+T[p2].weight;
	} 	
} 

void CharSetHuffmanEncoding(){
	int c,p1,i,m;
	char ch;
	int j=0;
	char cd[n+1];
	int start;
	cd[n]='\0';
	for(i=1;i<=26;i++)
	    H1[i].ch='a'+i-1;
	for(i=1;i<=26;i++)
	    H2[i].ch='a'+i-1;
	printf("每个字符所对应的哈夫曼编码为：\n");
	for(i=1;i<=n;i++){
		while(cs[j]==0)j++;
		ch=i+96;
		start=n;
		c=i;
		p1=T[c].parent;
		while(p1>0){
			if(T[p1].lchild==c)cd[--start]='0';
			else cd[--start]='1';
			c=p1;
			p1=T[p1].parent;
			
		}
		strcpy(H1[j+1].bits,&cd[start]);
		printf("%c:%s\n",H1[j+1].ch,H1[j+1].bits);
		j++;
	}
	printf("赫夫曼编码为：\n"); 
	while(c1[i]!='\0'){
    	if(c1[i]<='Z')m=c1[i]-'A';
    	else m=c1[i]-'a';
    	if(c1[i]!=' ')printf("%s",H1[m+1].bits);
    	i++;
     }
     while(c1[i]!='\0'){
    	if(c1[i]<='Z')m=c1[i]-'A';
    	else m=c1[i]-'a';
    	if(c1[i]!=' ')printf("%s",H1[m+1].bits);
    	i++;
    }
}


int main(){
	int i=0;
	n=sum();
	CreateHuffmanTree();
	CharSetHuffmanEncoding();
	return 0;
}