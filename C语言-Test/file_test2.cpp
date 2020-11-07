#include<stdio.h> 
#include<stdlib.h>
int main(){
	FILE *fp;
	//fp=fopen(filename,mode);//filename文件名，mode使用模式：r,w,a,读，写，添加 
	//
	if(fp=fopen("cs.txt","r")){
		printf("success");
	}
	else{
		printf("no");
		exit(0);
	}
	printf("\n");
	
	int x,i,y,z,j;
	x=(i=2,y=6,z=8);
	printf("%d\n",x);
	
//	for(i=0;j=7;++i==--7)
//		printf("shuchu");
	return 0;
}