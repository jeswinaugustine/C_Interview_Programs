/** WAP  to print a[986] using p*   */


#include "stdio.h"
#include "stdlib.h"

int main () {
unsigned long a[1000];
unsigned char *p;

/* a[986] = 9089299509; */

p = (char *) malloc(sizeof(unsigned long));

if(p == NULL) {
    return 1;
}
p = (char*) &a[986];
memset(p,9089299509,sizeof(unsigned long));

printf("Val  2 = %lu \n", a[986]);

return 0;
}

#if 0
-------O/P--------
Val = 9089299509
      892679477
      3834029160418063669
#endif
