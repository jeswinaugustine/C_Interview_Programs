/* Allocate a 2 dimentional array nxc and free it */
#include <stdio.h>

int main() {

int r=3;
int c=4;

int **ptr= NULL;

ptr =(int**) malloc(r*sizeof(int*));
for(int i=0;i<r;i++){
    ptr[i] = (int*) malloc(c*sizeof(int*));
}

for(int i=0;i<r;i++){
    for(int j=0;j<c;j++) {
        *(*(ptr+i)+j) = (i+1)* (j+1);
        printf(" %d ",*(*(ptr+i)+j) = (i+1)* (j+1));
    }
    printf("\n");
}

for(int i=0;i<r;i++){
    free(ptr[i]);
}
free(ptr);
return 0;
}
