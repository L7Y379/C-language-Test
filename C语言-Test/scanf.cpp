# include <stdio.h>
int main(){
int i;
printf("please enter the right password\n"); 
scanf("%d",&i);
while(i != 520)
{
printf("please enter the right password\n");
scanf("%d",&i);
}
printf("right!good boy!\n\n");
return 0;
}