#include<stdio.h>
#include"string.h"
int main(){
	float i,j=1,k=2;
	char ch;
	//scanf("%f",&i);
	//ch=getchar();
	i=j>k?j:k;
	//printf("i wei %e",i);
	//printf("%c",ch);
	int m=9;
	switch(ch){
		case 'l':
		printf("%c%c",ch,ch);
		break;
		case 'm':
		printf("%c",ch);
		break;
		default:
		break;
	}
	printf("%c\n",m);
	m=m+'0';
	printf("%c\n",m);
	
	
	int a[10]={10,11,12,13,14},len;
	int *q;
	char str[10];
	char *p=str;                 //字符串和数组不同，都不用 加& 
	q=a;
	printf("%d\t%d\t%d\t\n",q[0],q[1],q[1]);
	printf("%d\t%d\t%d\t\n",*q,*(q+1),*(q+2));
	gets(str);
	len=strlen(str);
	printf("%d\n",len);
	printf("%c\n",*p);
	while(*p!='\0'){
		putchar(*p);
		p++;
	}
	printf("\n");
	
	char *pd[4]={"one" ,"two","three","four"};//指针数组   
	while(*pd[2]!='\0'){
		printf("%c",*pd[2]++);//带*表示第一个字符 
		
	}
	
	pd[2]=pd[0];
	printf("%s",pd[2]);
	return 0;
}