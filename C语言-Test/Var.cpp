#include<stdio.h>
#include<stdlib.h>
#define  N 100

int m;   //ȫ�ֱ��� extern����������� 
int math(int &i){
	extern int m;    //˵������������ⲿ�����ͺ�����ͬһԴ��������˵����ʡ�ԣ� 
	i=i*i;
	return i; 
}

int main(){
	int j=100;     
	extern int m;   //˵������ 
	if(1){
		int j;      //��������оֲ����� auto 
		j=1;
		printf("%d\n",j);
	} 
	printf("%d\n",j);
	
	char *str[10];
	if((str[0]=(char*)malloc(128))=NULL){   //����ʧ��
		printf("����ʧ��\n");
		exit(0); 
	}
	printf("����ɹ�\n");
	
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
