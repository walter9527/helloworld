#include "common.h"

#if 0
void test01()
{
    // num 拥有一个合法空间
    int num = 10;

    // 需求: 请定义一个指针变量, 保存 num 地址
    int *p = &num;
    printf("%d\n", *p);
    printf("%p\n", p);

    *p = 100;
    printf("%d\n", num);

    scanf("%d", p);
    printf("%d\n", num);
}

// 指针的宽度, 是指向类型的长度
void test02()
{
    int num = 0x01020304;
    char *p1 = &num;
    short *p2 = &num;
    char a = 12;
    printf("%#x\n", num);
    printf("%#x\n", *p1);
    printf("%#x\n", *p2);
    printf("%#x\n", a);
}

// 指针的跨度, 是指向类型的长度
void test03()
{
    int num = 0x01020304;
    int *p = &num;
    short *p2 = &num;
    char *p3 = &num;

    printf("p = %u\n", p);
    printf("p + 1 = %u\n", p + 1); // 跨了 4 字节

    printf("==================\n");

    printf("p2 = %u\n", p2);
    printf("p2 + 1 = %u\n", p2 + 1); // 跨了 2 字节

    printf("==================\n");

    printf("p3 = %u\n", p3);
    printf("p3 + 1 = %u\n", p3 + 1); // 跨了 1 字节
}

void test04()
{
    int num = 0x01020304;

    char *a = &num;

    void *p = &num;

    printf("%#x\n", *(short *)(a + 1));

    printf("%#x\n", *(short *)((char *)p + 1));
}

void test05()
{
    int arr[5] = {0};
    int len = sizeof(arr) / sizeof(arr[0]);

    int *p = arr;
    for (int i = 0; i < len; ++i) {
        start:
        printf("请输入第 %d 个整数: ", i + 1);
        int flag = scanf("%d", p);
        flush();
        if (flag != 1) {
            printf("输入错误, 请重新输入!\n");
            goto start;
        }
        p++;
    }
    p = arr;
    printf("arr = [");
    for (int i = 0; i < len; ++i) {
        printf("%d", *(p++));
        if (i == len - 1) {
            printf("]\n");
            break;
        }
        printf(", ");
    }
}

void test06()
{
    int arr[10] = {10, 20, 30, 40, 50};
    printf("arr = %d\n", arr);
    printf("arr + 1 = %d\n", arr + 1);
    printf("arr 跨度 = %ld\n", (long)(arr + 1) - (long)arr); // 4
    split_line();
    printf("&arr + 1 = %d\n", &arr);
    printf("&arr + 1 = %d\n", &arr + 1);
    printf("&arr 跨度 = %ld\n", (long)(&arr + 1) - (long)&arr); // 40

    split_line();

    int *p = arr;
    int *p2 = arr + 3;

    printf("%ld\n", p - p2);

    printf("%d\n", p2 > p);

    printf("%d\n", p2[1]);
}

void test07()
{
    int arr[10] = {10, 20, 30, 40, 50};
    int *p = arr;

    printf("%d\n", *p++); // 10
    printf("%d\n", (*p)++); // 20
    printf("%d\n", *(p++)); // 21
}

void test08()
{
    int num1 = 10;
    int num2 = 20;
    int num3 = 30;
    int *arr[3] = {&num1, &num2, &num3}; // 指针数组
    char *arr2[3] = {"hehe", "haha", "heihei"};
    printf("%lu\n", sizeof(arr)); // 所有指针长度都相等, 与指向类型无关
    printf("%lu\n", sizeof(arr2)); // 所有指针长度都相等

    printf("%c\n", *(arr[1] + 1)); // 获取第1个元素的第1个字符
}

void test09()
{
    char *arr[3] = {"hehe", "haha", "heihei"};

    printf("%lu\n", sizeof(arr));
    printf("%c\n", *(arr[1] + 1));
}


void test10()
{
    int arr[5] = {10, 20, 30, 40};
    int (*p)[5] = &arr; // 数组指针

    printf("%lu\n", sizeof(p)); // 8

    printf("p = %u\n", p);
    printf("p + 1 = %u\n", p + 1); // 跳过整个数组

    int *p1 = *p; // 将首地址强转成首元素地址
    int i = *(p1 + 3);
    printf("%d\n", i);
    printf("%d\n", *(*p + 3)); // 等价于上面转换
    printf("%d\n", p[0][3]); // 转换成二维数组的形式


}

void my_swap(int *p1, int *p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void test11()
{
    int data1 = 10, data2 = 20;
    printf("data1 = %d, data2 = %d\n", data1, data2);
    split_line();
    my_swap(&data1, &data2);
    printf("data1 = %d, data2 = %d\n", data1, data2);
}

void put_pointer(int **p) {
    static int num = 200;
    *p = &num;
}

void test12()
{
    int *p = NULL;

    int num = 100;

    p = &num;

    put_pointer(&p);

    printf("%d\n", *p);
}

void my_input_array(int *p, int len) {
    printf("您需要输入 %d 个整数\n", len);

    for (int i = 0; i < len; ++i) {
        start:
        printf("请输入第 %d 个整数: ", i + 1);
        int flag = scanf("%d", p);
        flush();
        if (flag != 1) {
            printf("您的输入有误, 请重新输入!\n");
            goto start;
        }
        p++;
    }
}

void my_print_array(int *p, int len) {
    printf("[");

    for (int i = 0; i < len; ++i) {
        printf("%1d", *p++);
        if (i == len - 1) {
            break;
        }
        printf(", ");
    }

    printf("]\n");
}

void test13()
{
    int arr[5] = {0};

    int len = sizeof(arr) / sizeof(arr[0]);

    my_input_array(arr, len);

    my_print_array(arr, len);
}

void my_print_two_array(int *arr, int row, int col) {


    for (int i = 0; i < row; ++i) {
        my_print_array(arr+ i * col, col);
    }
}

void test14()
{
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    int row = sizeof(arr) / sizeof(arr[0]);
    int col = sizeof(arr[0]) / sizeof(arr[0][0]);

    my_print_two_array(arr, row, col);
}
typedef unsigned long long int BIG;

BIG fun(int num) {
    if (num == 1 || num == 2) {
        return 1;
    } else {
        return fun(num - 1) + fun(num - 2);
    }
}

int* get_addr() {
    static int arr[5] = {1, 2, 3, 4, 5};
//    int arr = 110;
    printf("%#x\n", &arr);
    return &arr;
}

void test15()
{
    int *p = NULL;

    p = get_addr();

    printf("*p = %d\n", *p);
    printf("*p = %#x\n", p);
}

int my_add(int a, int b) {
    return a + b;
}

void test16()
{
    printf("%#x\n", my_add); // 函数名可以作为函数的入口地址

    int (*p)(int, int) = NULL; // 声明一个函数指针
    printf("%d\n", sizeof(p)); // 8 个字节

    p = my_add; // 函数指针与函数名建立关系
    printf("%d\n", sizeof(p)); // 8 个字节


    printf("%d\n", p(1, 2)); // 这里不需要写作 *p, *p 没有意义, ***p也会优化成p
    printf("%d\n", my_add(1, 2)); // 两者相同

}

#endif


int my_add(int a, int b) {
    return a + b;
}
int my_sub(int a, int b) {
    return a - b;
}
int my_mul(int a, int b) {
    return a * b;
}

// 定义一个函数, 实现上述功能
int my_calc(int a, int b, int (*p)(int, int)) {
    return p(a, b);
}

void test17()
{
    printf("%d\n", my_calc(10, 20, my_add));
    printf("%d\n", my_calc(10, 20, my_sub));
    printf("%d\n", my_calc(10, 20, my_mul));

}

int main(int argc, char *argv[]) {
    test17();
    return 0;
}