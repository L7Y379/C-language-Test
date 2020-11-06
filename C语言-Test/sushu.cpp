#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){              //ÕÒËØÊı
 	
	char a[]="uestc";
	char *b="cst";
	printf("%s\n",a);
	//printf("%s\n",b);
	a[0]='a';
	printf("%s\n",a);
	//b[1]='s';
	//b=a;
	//b[1]='u';
	//a=b;
	strcpy(a,"chen");
	printf("%s\n",a);
	printf("%s\n",b);
	b="du";
	return 0;

	return 0;
}
