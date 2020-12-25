#include <stdio.h>
int num = 100; // 静态全局变量

void my_fun() {
    printf("全局函数(普通函数)\n");
}

static void my_static_fun() {
    printf("局部函数(静态函数)");
}