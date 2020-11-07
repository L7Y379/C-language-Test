#include<stdio.h>
int math(int &i){
	i=i*i;
	return i; 
}

int fuc(int result) {
	if(result==1){
		return 1;
	}
	return result*fuc(result-1);
}

int main(){
	void swap(int *p ,int *q); //∂®“Â 
	printf("Hello,world!\n");
	int i,k;
	i=5;
	k=math(i);
	printf("%d\n",k);
	printf("%d\n",i);
	int a,b;
	a=10,b=20;
	swap(&a,&b);
	printf("a=%d b=%d\n",a,b);
	
	int m=5;
	printf("%ld",fuc(m));
	return 0;
} 
void swap(int *p ,int *q){
	int temp;
	temp=*q;
	*q=*p;
	*p=temp;
}
