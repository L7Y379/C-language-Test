#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student{
		int age;
		char name[10];
		float count;
		int len;
	};
	
struct teacher{
		int age;
		char name[10];
		int count;
		int len;
	}Lisa,Bob,Luoyue;
	
struct slist{    //链表 
	int num;
	struct slist *next;
};

union{    //联合，节省空间，同时间只有一个变量 
	int a;
	float b;
	char c;
}value; 

enum color {red,blue,green};

int main(){
	
	value.a=1;
	//value.b=3.3;
	printf("%d\n",value.a);
	printf("%f\n",value.b);
	
	enum color col;
	col=red;
	printf("%d\n",col);//输出0，red为第0个
	printf("%c\n",col);
	// col=yellow;   错误 
	
	value.b=444;
	printf("%f\n",value.b);
	
	struct slist *head,*p1,*q1;
	head=(struct slist *)malloc(sizeof(struct slist));
	//head->next->num=2;
	head=p1;
	p1->next=q1;
	p1->num=11;
	printf("%d\n",p1->num);
	printf("aaaa\n"); 
	
	
	student stu1;
	stu1.age=15;
	gets(stu1.name);
	stu1.len=strlen(stu1.name);
	printf("%d %d %c ",stu1.age,stu1.len,stu1.name[5]);
	putchar(stu1.name[5]);
	printf("\n");
	
	struct student stu2={18,"qinqin",100000,15};
	printf("%d %d %s \n",stu2.age,stu2.len,stu2.name);
	
	teacher tch[5];
	struct teacher *p;
	p=&Lisa;
	(*p).age=25;
	p->count=200;
	p->age=15;     
	printf("%d %d %d\n",Lisa.age,Lisa.count,p->age);
	
	   
	
	return 0; 
} 