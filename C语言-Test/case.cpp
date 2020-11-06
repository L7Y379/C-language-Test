#include<stdio.h>
int main(){
	int score;
	printf("Please write you score:");
	scanf("%d\n",&score);
	switch(score/10)
	{
		case 10:
		case 9:
            printf("You score level is A");
            break;
		case 8 :
		  printf("You score level is B");
            break;
          case 7:
            printf("You score level is C");
            break;
          case 6:
            printf("You score level is D");
            break; 
         	case 5:
		case 4:
		case 3:
		case 2:
		case 1:
		case 0:
		  printf("You score level is E");
            break; 
          default:
            printf("Please write the right score");  
	}
	return 0;
} 