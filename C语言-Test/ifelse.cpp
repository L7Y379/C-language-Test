#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(void)
{
int chosen = 0;
int guess = 0;
int count = 3;
int limit = 20;

srand(time(NULL));
chosen = 1 + rand() % limit;

printf("\nThis is a guessing game.");
printf("\nI have chosen a number between 1 and 20"
" whice you must guess.\n");
for(;count > 0;--count)
{
printf("\nYou have %d tr%s left.",count,count == 1 ? "y" : "ies");
printf("\nEnter a guess:");
scanf("%d",&guess);
//如果猜对了数字 
if(guess == chosen)
{
printf("\nCongratulations.You guessed it!\n");
if(3 == count)
printf("\nBrats, you are so lucky!\n");
else if(2 == count)
printf("\nNot bad\n");
else
printf("\nYou almost fail!\n\n");
return 0;
}
//如果输入的是无效数字
else if(guess < 1 || guess > 20)
printf("I said the number is between 1 and 20.\n");
//如果猜错了 
else 
printf("Sorry,%d is wrong.My number is %s than that.\n",
guess,chosen > guess ? "greater" : "less"); 
}
printf("\nYou have had three tries and failed.The number was %ld\n",
chosen);
return 0; 
}
