#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SQUARE(a) ((a)*(a)*(a))


int func(int *p){
	return (*p--=3)-1;
}
int main(){
 /*  int a,i;
   scanf("%d",&a);
   while(!(a%10)){
      a=a/10;
}
   do{
      i=a%10;
      printf("%d",i);
      a=a/10;
   }while(a);
 
   char str1[2018]={"uestc"};
   int b[2018];
   printf("%d\n",sizeof(str1));
   printf("%d\n",sizeof(b));
   
   float d;
   scanf("%f",&d);
   printf("%f\n",d);
   if(d==3.5){
   	printf("%d\n",d);
   }
   else{
	printf("0");
	}
  	
	char p[10]="uestc";
	char q[]="xyz";
	int i,j;
	i=0;
	while(*(p+i)!='\0')i++;
	j=0;//i++;
	while(*(q+j)!='\0'){
		*(p+i)=*(q+j);
		j++;
	}
	printf("%s\n",p);
	printf("%c   %c",p[5],*(q+1));

	int arr[]={
		10,7,5
	};
	int *p=arr+1;
	int i=1;
	printf("%d",func(p)+*p);
	switch(i){
		printf("s");
		case 1:printf("h");
	}
	
	
	FILE *fp1,*fp2;
	fp1=fopen("file.txt","w");
	fp2=fopen("file.txt","w");
	fputc('a',fp1);
	fputc('b',fp2);
	fclose(fp1);
	fclose(fp2);

	int a[]={1,2};
	int *p=a,i;
	printf("%d",p[1]);


	int a=5,b;
	b=SQUARE(a++);
	printf("a=%d,b=%d",a,b);

	int i=0;
	while(i++<2){
		printf("%d",i);
	}
	
	
	int a;
	a=10.0/3;
	printf("%f\n",10.0/3);
	printf("%d\n",sizeof(10.0/3));
	printf("%d\n",sizeof(a));
	printf("%d\n",a);
	
	
	char s[20];
	gets(s);
	puts(s);
	printf("%d",sizeof("aaa"));
	
	
	
	void fun(int,int[]);
	int arr[]={1,2,3,4};
	int i;
	fun(4,arr);
	for(i=0;i<=3;i++){
		printf("%d",arr[i]);
	}
	
	
	
	int i;char s[20],*p;
	for(i=0;i<20;i++){
		s[i]=getchar();
		
	}
	s[i]='\0';
	p=s;
	while(*p++){
		putchar(*(p-1));
	}
	
	
	int i,n;
	scanf("%d",&n);
	printf("%d=",n);
	for(i=2;i<=n;i++){
		while((n/i)!=1){
			if(n%i==0){
				printf("%d*",i);
				n=n/i;
			}
			else{
				break;
			}
		}
	}
	printf("%d",n);
	*/
	
	char a[]="uestc";
	char *b="cst";
	//printf("%s\n",a);
	a[0]='a';
	b[1]='s';
	b=a;
	b[1]='u';
	//a=b;
	strcpy(a,"cheng du");
	printf("%s\n",a);
	printf("%s\n",b);
	b="du";
	return 0;
}

void fun(int n,int arr[]){
	int *p=0;
	int i=0;
	while(i<n){
		p=&arr[i];
		i++;
	}
	*p=0;
}
