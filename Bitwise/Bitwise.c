#include "stdio.h"
#include "stdlib.h"

int main(){

    int a = 9,b;
    char buffer1 [33];
    char buffer2 [33];
    /* 1. How to set a particular bit in a variable or Register? */
    b = a  | 1<<1;
    itoa(a,buffer1,2);
    itoa(b,buffer2,2);
    printf("Setting 2nd bit to 1 \n");
    printf("Original Number: %s , Changed Number: %s\n\n",buffer1,buffer2);

    /* 2. How to clear a particular bit in a number? */

    a=11;
    b = a  & ~(1<<1);
    itoa(a,buffer1,2);
    itoa(b,buffer2,2);
    printf("Clearing 2nd bit \n");
    printf("Original Number: %s , Changed Number: %s\n\n",buffer1,buffer2);


    /* 3. How to toggle or flip a particular bit in a number? */

    a=8;
    b = a  ^ 1<<1;
    itoa(a,buffer1,2);
    itoa(b,buffer2,2);
    printf("Toggle 2nd bit \n");
    printf("Original Number: %s , Changed Number: %s\n\n",buffer1,buffer2);


    /* 3. How to check particular bit is set or not in a number?*/

    a=8;
    for (int i=0;i<4;i++) {
        printf("%d bit is %s \n",i, a & (1<<i)? "set" : "not set" );
    }

    return 0;
}
