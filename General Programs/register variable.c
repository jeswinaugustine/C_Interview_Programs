int main() {

    int x = 20;
    /* register int y = 30; throws error */
    int y = 30;

    int *p = &x;
    register int *q = &y;

    int z1 = (*p) * y;
    int z2 = x  * (*q) ;

    if (z1 < z2) {
      printf("A");
    }
    else {
      printf("B");
    }
}
