#include<stdio.h>
#include<stdlib.h> 
typedef struct stu{
	int stuID;
	char stuName[21];
	int Age;
}ElemType;

typedef struct node{
	ElemType data;
	struct node *next;
}ListNode,*LinkedList;

void LinkedListInit(LinkedList *L){
     *L=(ListNode*)malloc(sizeof(ListNode));
      	if(!L){
      	printf("申请空间失败！");
		exit(0); 
          }
		(*L)->next=NULL;	
}

void LinkedListout(LinkedList L){
     L=L->next;
	 printf("\nID\tName\tAge\n");
	while(L!=NULL){
		printf("%d\t",L->data.stuID); 
		printf("%s\t",L->data.stuName);
		printf("%d\n",L->data.Age);  
	     L=L->next;
		
	}
}

ElemType read(){
	 ElemType e;
	 scanf("%d",&e.stuID);
	 scanf("%s",e.stuName);
	 scanf("%d",&e.Age);
	 return e;
}

int  leave(LinkedList *l,LinkedList e){
	LinkedList p,pre;
	pre=*l;
	p=(*l)->next;
	while(p!=NULL){
		if(p->data.stuID==e->data.stuID){
			pre->next=p->next;
			free(p);
			p=NULL;
	      	return 0;
		}
		else p=p->next;
	}
}

int length(LinkedList l){
	LinkedList p;
	int i=0;
	LinkedListInit(&p);
	p=l->next;
	while(p!=NULL){
		p=p->next;
		i++;
	}
	return i;
} 

void LinkedList1(LinkedList *L){
      int  i,n; 
      printf("请输入学生总人数：\n");
      scanf("%d",&n);
      *L=(ListNode*)malloc(sizeof(ListNode));
      	if(!*L){
      	printf("申请空间失败！");
		exit(0); 
          }
      LinkedList  p,tail;
      (*L)->next=NULL;
      tail=*L;
      printf("请按学号、姓名、年龄的顺序输入你要创建链表的数据：\n");
      for(i=0;i<n;i++){
      	p=(ListNode*)malloc(sizeof(ListNode));
      	if(!p){
      	printf("申请空间失败！");
		exit(0); 
          }
	     p->data=read();
	     p->next=NULL;
	     tail->next=p;
	     tail=p;
      }
		      	
}


void LinkedListInsert(LinkedList *L){
      LinkedList pre,q,p;     
      pre=*L;
      p=(*L)->next;
	 q=(ListNode*)malloc(sizeof(ListNode));
	 LinkedListInit(&q);
      printf("请输入你要插入链表L3的学生的学号、名字和年龄：\n");
      q->data=read();
    	 while(p&&(q->data.stuID>p->data.stuID)){
		p=p->next;
		pre=pre->next;
	 }
	 q->next=p;
	 pre->next=q;
	
}

void	LinkedListreverse(LinkedList *lc) {
     int i=length(*lc);
	LinkedList l,p1,p2,p3,pre,pre1,pre2;
	LinkedListInit(&l);
	while(i>=2){
	pre=*lc;
	pre1=*lc;
	pre2=*lc;
	p1=(*lc)->next;
	p2=(*lc)->next;
	p2=p2->next;
	pre2=pre2->next;
	if(p1->data.stuID>p2->data.stuID){
		p3=p2;
		p2=p2->next;pre=pre2;pre2=pre2->next;
		
	}
	else {
		p3=p1;
		p2=p2->next;pre2=pre2->next;
		pre=pre1;
	}
	while(p2){
		if(p2->data.stuID>p3->data.stuID)
		p2=p2->next;
		else{
			p3=p2;
			p2=p2->next;pre=pre2;pre2=pre2->next;
			
		}
	}
	
	pre->next=p3->next;
     leave(lc,p3);
     p3->next=NULL;
	p3->next=l->next;
	l->next=p3; 
	i--;
	}
	pre=(*lc)->next;
	pre->next=l->next;
	l->next=pre;

}


void LinkedListAsd(LinkedList *lc){
	int i=length(*lc);
	LinkedList l,p1,p2,p3,pre,pre1,pre2;
	LinkedListInit(&l);
	while(i>=2){
	pre=*lc;
	pre1=*lc;
	pre2=*lc;
	p1=(*lc)->next;
	p2=(*lc)->next;
	p2=p2->next;
	pre2=pre2->next;
	if(p1->data.stuID<p2->data.stuID){
		p3=p2;
		p2=p2->next;pre=pre2;pre2=pre2->next;
		
	}
	else {
		p3=p1;
		p2=p2->next;pre2=pre2->next;
		pre=pre1;
	}
	while(p2){
		if(p2->data.stuID<p3->data.stuID)
		p2=p2->next;
		else{
			p3=p2;
			p2=p2->next;pre=pre2;pre2=pre2->next;
			
		}
	}
	
	pre->next=p3->next;
     leave(lc,p3);
     p3->next=NULL;
	p3->next=l->next;
	l->next=p3; 
	i--;
	}
	pre=(*lc)->next;
	pre->next=l->next;
	l->next=pre;

}

void Listmerge(LinkedList *la, LinkedList *lb, LinkedList *lc){
	LinkedList pa,pb,pc;
	pa=(*la)->next;
	pb=(*lb)->next;
	*lc=*la;
	pc=*lc;
	while((pa!=NULL)&&(pb!=NULL)){
		if(pa->data.stuID<pb->data.stuID){
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else if(pa->data.stuID>pb->data.stuID){
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
		else if(pa->data.stuID==pb->data.stuID){                                 
			if(pa->data.Age<=pb->data.Age){
				pa=pa->next;
				pc->next=pb;
				pc=pb;
				pb=pb->next;
			}
			else{
				pb=pb->next;
				pc->next=pa;
				pc=pa;
				pa=pa->next;
			}
		}
	} 
	if(pa)pc->next=pa;
	else pc->next=pb;

} 

int main(){
     LinkedList L1,L2,L3;
     LinkedListInit(&L1);
     LinkedListInit(&L2);
     LinkedListInit(&L3);
     printf("请创建链表L1!");
     LinkedList1(&L1);
     printf("\nL1按学号升序排列为：");
     LinkedListAsd(&L1);
     LinkedListout(L1);
     printf("\nL2请创建链表L2!");
     LinkedList1(&L2);
     printf("\n按学号升序排列为：");
     LinkedListAsd(&L2);
     LinkedListout(L2);
     printf("\nL1与L2保序合并后的链表L3为："); 
     Listmerge(&L1,&L2,&L3);
    	LinkedListout(L3);
     LinkedListInsert(&L3);
     printf("\n插入新元素后的L3为：");
     LinkedListout(L3);
     printf("L3按学号逆序排列为：");
	LinkedListreverse(&L3); 
     LinkedListout(L3);
	printf("实验完成！");
	return 0;
} 
