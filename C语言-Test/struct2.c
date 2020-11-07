#include<stdio.h>
#include<string.h>
struct student{
		int age;
		char name[10];
		float count;
		int len;
	};
	
struct teacher{
		int age;
		char name[10];
		float count;
		int len;
	}Lisa,Bob,Luoyue;
	
int main(){
	student stu1;
	stu1.age=15;
	gets(stu1.name);
	stu1.len=strlen(stu1.name);
	printf("%d %d %c ",stu1.age,stu1.len,stu1.name[5]);
	putchar(stu1.name[5]);
	printf("\n");
	
	struct student stu2={"18","qinqin","100000","15"};
	printf("%d %d %c ",stu2.age,stu2.len,stu2.name[5]);
	return 0; 
} 