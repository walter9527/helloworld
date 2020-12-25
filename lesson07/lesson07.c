#include "common.h"

#define MY_ADD(a, b) a + b
#define MY_MUL(a, b) a * b

void test01()
{
    printf("%d\n", MY_MUL(MY_ADD(10 + 10, 20 + 20), MY_MUL(10 + 10, 20 + 20))); // 460
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}