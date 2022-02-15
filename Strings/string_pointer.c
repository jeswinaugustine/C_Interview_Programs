#include "stdio.h"


int main() {

    char *p = "bangalore";
    char c = 'a';
    *p = 'a\0';
    printf("%s",p);

    return 0;

}
