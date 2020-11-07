#include <stdio.h>
#define SIZE 30
void assign(int s[]){
    int i = 0;
    while( i < SIZE)  {
             s[i]=3+2*i;
		   i++;          
                      
    }
}

void get_average(int *parray, float aver[]){
    float sum = 0;
    int i = 0, j = 0;
    while( i < SIZE ) {
        sum += parray[i];
        if(  (i+1) % 6 == 0  )  {
             aver[j]=sum/6;
		   sum=0;                  
                               
           j++;              
        }
        i ++;
    }
}
int main ( ){
    int num_array[SIZE];
    float average[SIZE/6];
    int i;
    assign(num_array);
    get_average(   num_array,average            );     
    for(i = 0;i < SIZE/6; i++)
        printf("%f\n", average[i]);
    return 0 ;                          
}