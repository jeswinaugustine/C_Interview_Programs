#include <stdio.h>
#define A(a,b) a##b
#define B(a) #a
#define C(a) B(a)

main()
{
 printf("%s\n",C(A(1,2)));
 printf("%s\n",B(A(1,2)));
}
