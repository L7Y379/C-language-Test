#include<stdio.h>
int main(){
	int i;
	char j;
     int *pL=&i;
     char *pY=&j;
	printf("%p %p %p %p\n",pL,pY,&i,&j);
	for(i=1;i<=5;i++)
	{
	    
	    printf("%p\n",pL+=2);
	    printf("%p\n",pY-=2);
	} 
	return 0;
} 