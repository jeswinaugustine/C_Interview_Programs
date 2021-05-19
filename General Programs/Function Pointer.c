#include<stdio.h>
void Hello();

typedef void (*FP)();

FP fun (int);

int main() {

    FP (*main_f)(int) = NULL;
    FP return_f;
    main_f = fun;
    return_f = (*fun)(30);
    (*return_f)();

    return 0;
}

void Hello() {
    printf("hello");
}

FP fun (int a) {

FP p = Hello;
printf("Number %d\n",a);
return p;
}
