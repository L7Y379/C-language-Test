#include <stdio.h>
main(){ 
    int k=0;
    int c= 100;
    do   { 
      switch(c++) { 
        case 100: k++;break;
        case 101: k--;
        case 102: k += 2;break;
        case 103: k = k%2;continue;     
        case 104: k = k+10;break;                 
        default:  k = k/3;                 
      }                                     
      k++;
      printf("k=%d, c=%d\n",k, c);  
    }while(c < 103);
}
