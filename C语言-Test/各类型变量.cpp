#include<stdio.h>
#define  N 100

int m;   //ȫ�ֱ��� extern����������� 
int math(){
	extern int m;    //˵������������ⲿ�����ͺ�����ͬһԴ��������˵����ʡ�ԣ� 
	return m*m; 
}

int main(){
	int j=100;      
	if(1){
		int j;      //��������оֲ����� auto 
		j=1;
		printf("%d\n",j);
	} 
	printf("%d\n",j);
	
	extern int m;   //˵������
	m=20;
	printf("%d\n",math());
	return 0;
} 
