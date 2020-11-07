#include<stdio.h>
#include<math.h>
int main(){              //ÕÒËØÊı 
	int i,j;
	int a[101]={0};

	for(i=2;i<sqrt(100);i++){
		if(a[i]==0){
			printf("%d\t",i);
			for(j=i*2;j<=100;j=j+i){
				a[j]=1;
			}
		}
	}
	for(i=2;i<=100;i++){
		if(a[i]==0){
			printf("%d\t",i);
		}
	}
	return 0;
}
