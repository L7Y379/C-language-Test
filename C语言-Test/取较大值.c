#include<stdio.h>
int main(){
	int a,b,c;
	printf("请输入a的值:");
	scanf("%d",&a);
	printf("请输入b的值:");
	scanf("%d",&b);
	c=a>=b?a:b;
	printf("较大值为：%d\n",c);
	return 0;
} 