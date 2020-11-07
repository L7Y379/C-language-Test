#include<stdio.h>
#define  N 100

int m;   //全局变量 extern（定义变量） 
int math(){
	extern int m;    //说明变量（如果外部变量和函数在同一源程序内则说明可省略） 
	return m*m; 
}

int main(){
	int j=100;      
	if(1){
		int j;      //复合语句中局部变量 auto 
		j=1;
		printf("%d\n",j);
	} 
	printf("%d\n",j);
	
	extern int m;   //说明变量
	m=20;
	printf("%d\n",math());
	return 0;
} 
