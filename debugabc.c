#include <stdio.h>

int main(void) {
    int a[12];
    int b;
    long d;
    double c;
    struct abc {
    } z1, z2;
    printf("%u\n", sizeof(a)/sizeof a[0]);
    printf("int    %d\n", sizeof(b));
    printf("long   %d\n", sizeof(c));
    printf("double %d\n", sizeof(d));
    printf("struct %u\n", sizeof(z1));
}