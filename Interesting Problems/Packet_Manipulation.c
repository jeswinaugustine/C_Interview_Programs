
#include <stdio.h>      /* printf */
#include <string.h>     /* strcat */
#include <stdlib.h>     /* strtol */

// Function to convert decimal
// to binary number
void bin(char* n)
{
    if (n > 1)
        bin(n >> 1);

    printf("%d", n & 1);
}

int main() {

    char buffer[BUFF_SIZE];
    int len[10]={10,20,30,40,50,60,70,80,90};

    for (int i=0;i<len;i<++) {
        memcpy(buffer,&len[0],sizeof(4*sizeof(char));
    }

    printf("")
    return 0;
}
