#include <stdio.h>

int add(int a, int b)
{
    int sum = 0;
    printf("processing...\n");
    for (int i = 0; i < a; ++i) {
        printf("sum is %d\n", sum);
        sleep(5);
        sum = sum + b;
    }
    return sum;
}

//int main(void) {
//    printf("Hello, World!\n");
//    int sum;
//    sum = add(5, 3);
//    printf("sum of 5 and 3 is %d\n", sum);
//    return 0;
//}
