#include <stdio.h>

// 自动类型转换
// 有符号和无符号的转换
void test02()
{
     int data1 = -20;
     unsigned int data2 = 10;

     // int 在与 unsigned int 计算时, 会转为原数的补码(很大的正数)
     if (data1 + data2 > 0) {
         printf(">0\n");
     } else if (data1 + data2 < 0) {
         printf("<0\n");
     } else {
         printf("=0\n");
     }

    printf("%u\n", data1 + data2);
}

// int 和 double 的转换
void test03()
{
    int data1 = 10;
    printf("%llu\n", sizeof(data1 + 3.14)); // 8
}

// char 和 short 的字节数过小, 容易溢出, 因此在参加计算时会转为 int
void test04() {
    char ch = '\0';
    short data = 20;

    printf("%llu\n", sizeof(ch + ch)); // 4
    printf("%llu\n", sizeof(ch + data)); // 4
    printf("%llu\n", sizeof(data + data)); // 4
}

// 强制类型转换
void test05()
{
    float x = 3.14f;
    int j = 0;

    // 强制类型转换只在当前语句有效, 不改变 x 的值
    j = x; // 相当于 j = (int) x

    printf("j = %d\n", j);
}

void test06()
{
    int i = 0;
    while(1 == 1) {
        printf("请输出一个整数: \n");
        int flag = scanf("%d", &i);
        if (flag != 1) {
            printf("输入不正确\n");
        } else if (i % 3 == 0) {
            printf("ok\n");
        } else {
            printf("no\n");
        }
        fflush(stdin);
    }
}

void test07()
{
    int i = 0;
    printf("请输入4位数整数: \n");
    fflush(stdout);
    int flag = scanf("%d", &i);
    fflush(stdin);
    if (flag != 1) {
        printf("输入不正确, 请重新输入\n");
    } else if (i > 999 && i < 10000) {
        int k = 1000;
        while (k != 0) {
            printf("%d ", i / k);
            i = i % k;
            k = k / 10;
        }
    } else {
        printf("您的输入不合规则, 请输入4位整数\n");
    }
    fflush(stdin);
}

void test08()
{
    printf("abc = %llu\n", sizeof(5 / 0.2f));
}

// c语言中 0 为假, 其他都为真
void test09()
{
    if ('\0') {
        printf("true\n");
    } else {
        printf("false\n");
    }
}

void test10()
{
    int num = 10;
    2 > 3 && (num = 100); // 逻辑短路
    printf("num = %d\n", num);

    3 > 2 || (num = 100); // 逻辑短路
    printf("num = %d\n", num);

}

// & 将指定位清零
// | 将指定位置1
// ^ 判断两个位置, 不同为 1, 相同为 0, 用于将特定位翻转
void test11()
{
    // 将 data 的第 1, 5 位清 0, 第 3, 4 位置 1, 其他保持不变
    unsigned char data = 0b10101010;
    data = data & ~(0x01 << 5 | 0x01 << 1);
    data = data | (0x01 << 4 | 0x01 << 3);

    /**********************************\

     1101 1101 = ~(0010 0010) = ~(0x01 << 5 | 0x01 << 1)
     0001 1000 = 0x01 << 4 | 0x01 << 3

    \***********************************/
}



int main(int args, char* argv[])
{
    test11();
    return 0;
}