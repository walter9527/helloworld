#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <zconf.h>
#include "../include/lesson05.h"

// 返回值<=4字节的存放在寄存器, >4字节的存放在栈区
// abc() 相当于 abc(void)
void fun();

int al_1(int num);

int al_2(int num);

int main(int argc, char *argv[]) {
    test01();
}

int al_1(int num) {
    if (num == 1 || num == 2) {
        return 1;
    } else {
        return al_1(num - 1) + al_1(num - 2);
    }
}

int al_2(int num) {
    int result = 0;
    int last_1 = 1;
    int last_2 = 1;
    for (int i = 3; i <= num; ++i) {
        result = last_1 + last_2;
        last_2 = last_1;
        last_1 = result;
    }
    return result;
}


void fun() {
    int arr[5] = {0};
    int len = sizeof(arr) / sizeof(arr[0]);

    input_arr(arr, len);

    print_arr(arr, len);

    int max = get_max(arr, len);
    int min = get_min(arr, len);

    printf("最大值是 %d\n", max);
    printf("最小值是 %d\n", min);
}




