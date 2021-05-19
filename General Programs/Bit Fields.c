struct
{
    unsigned short icon : 8;
    unsigned short color : 4;
    unsigned short underline : 1;
    unsigned short blink : 1;
} screen;

struct Name
{
unsigned char fn : 3;
unsigned char mn : 4;
unsigned char ln : 1;
}name;


struct A
{
unsigned char c1 : 3;
unsigned char : 0; /* forces the next bit width member assignment to start from the next nibble.*/
unsigned char c2 : 4;
unsigned char c3 : 2;
}a;

typedef struct __attribute__((packed, aligned(1))) Ball {
    char c;
    int i;
} Ball_t;

int main() {
    printf("Size of int: %d\n",sizeof(int));
    printf("size of Screen: %d \n",sizeof(screen));
    printf("size of Name: %d \n",sizeof(name));
    printf("size of A: %d \n",sizeof(a));
    printf("size of Packed Ball_t: %d \n",sizeof(Ball_t));
}
