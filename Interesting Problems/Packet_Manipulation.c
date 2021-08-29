
#include <stdio.h>      /* printf */
#include <string.h>     /* strcat */
#include <stdlib.h>     /* strtol */

// Function to convert decimal
// to binary number

#define BUFF_SIZE 1500
void printBits(size_t const size, void const *ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }

        printf(" ");
    }
    puts("");
}


int main() {

    char buffer[BUFF_SIZE];
    int len[10]={10,20,30,40,50,60,70,80,90};

    memcpy(buffer,&len[0],sizeof(char)*4);

    #if 0
    for (int i=0;i<;i<++) {
        memcpy(buffer,&len[0],sizeof(4*sizeof(char));
    }
    #endif
    printBits(sizeof(int), buffer);
    return 0;
}
