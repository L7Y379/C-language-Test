#include<stdio.h>
#include"string.h"
int main(){
	char ch1,ch2;
	do{
		scanf("%c",&ch1);
		if(ch1==ch2){
			continue;
		}
		ch2=ch1;
		printf("%c",ch1);
		
	}while(ch1!='.');
	return 0;
}