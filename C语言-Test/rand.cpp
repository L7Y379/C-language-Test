#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int a=0,limit=20;
	srand(time(NULL));
	a=6+rand()%limit;
	printf("%d\n",a);
	return 0; 
}