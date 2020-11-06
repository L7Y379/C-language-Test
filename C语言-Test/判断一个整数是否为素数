#include<stdio.h>
#include<math.h>
 int isprime(int n){
 	int m;
 	for(m=2;m<=sqrt(n);m++)  //sqrt为开平方函数 
 	    if(n%m==0)return 0;
     return 1;
 } 
 int main(){
 	int m;
 	printf("Input the data:");
 	scanf("%d",&m);
 	if(m<=1){
	     printf("%d is not a prime\n",m);	
	 }
 	 else if(isprime(m)){
	 	printf("%d is a prime\n",m);	
	 }
	 else{	
	     printf("%d is not a prime\n",m);
	 }
	 return 0;
 }