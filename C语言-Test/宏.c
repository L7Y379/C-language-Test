#include<stdio.h>
#include<string.h>
#define  N 100   //���滻
#define  HELLO "nishisb\n" 
#define  MAX(a,b) a>b?a:b
#define  EVEN(a) a%2==0?1:0

int main(){
	puts(HELLO);
	printf("%s\n",HELLO);
	printf("%d\n",N);
	
	int x,y;
	x=2;y=5;
	printf("MAX SHI %d\n",MAX(x,y));
	
	if(EVEN(9+1))     //���ñ��ʽ����ִ��% 
		printf("is even");
	else
		printf("is odd");
		
	 
	return 0;
} 

