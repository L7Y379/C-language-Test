#include <stdio.h>
int i;

  int main() {
   print_all_rows();
   return 0;
 }
void print_one_row(void){

  for (i=1; i<= 5; i++)
    printf("*");
}
void print_all_rows(void){
  for (i = 1; i <= 5; i++) {
    print_one_row();
    printf("\n");
  }
}                 