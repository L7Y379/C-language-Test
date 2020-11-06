#include<stdio.h>
int main(){
    float a,b,c,*p;
    a=1.5;
    p=&a;
    printf("%f\n",a);
    int *p=(int*)&a;
    printf("%d\n",*p);
    return 0;
    
}