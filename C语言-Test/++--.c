#include<stdio.h>
int main(){
	int x=2,y=3,z;
	z=++x<=y--?--y==1?y--:--y:y--;
	printf("%d%d%d\t",x,y,z);
	return 0; 
} 