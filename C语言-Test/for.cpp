#include <stdio.h>
int main( ){
int i,j,k;
j=1;k=0;
for(i=1;i<=10;i+=2) 	{  j=j*i; k=k+j; }
printf("first k=%d\n",k);                          
j=1;                                              
k=0;
for(i=1;i<=10;i+=2)     
  j=j*i;
  k=k+j;
printf("second k=%d\n",k);                             
return 0;
}