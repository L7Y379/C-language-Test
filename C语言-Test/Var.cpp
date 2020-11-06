#include<stdio.h>
#include<stdlib.h>
#define  N 100

int m;   //全局变量 extern（定义变量） 
int math(int &i){
	extern int m;    //说明变量（如果外部变量和函数在同一源程序内则说明可省略） 
	i=i*i;
	return i; 
}

int main(){
	int j=100;     
	extern int m;   //说明变量 
	if(1){
		int j;      //复合语句中局部变量 auto 
		j=1;
		printf("%d\n",j);
	} 
	printf("%d\n",j);
	
	char *str[10];
	if((str[0]=(char*)malloc(128))=NULL){   //分配失败
		printf("分配失败\n");
		exit(0); 
	}
	printf("分配成功\n");
	
	float t;
	scanf("%f",&t);
	if(t==3.5){
		printf("success");
	}
	else{
		printf("no");
	}
	printf("%f",t);
	return 0;
} 
