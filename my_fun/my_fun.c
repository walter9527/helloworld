#include <stdio.h>

#define SIGN_INT_MAX ~(1 << 31)
#define SIGN_INT_MIN 1 << 31

extern void flush();

void print_arr(int arr[5], int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int get_min(int arr[5], int len) {
    int min = SIGN_INT_MAX;
    for (int i = 0; i < len; ++i) {
        min = arr[i] < min ? arr[i] : min;
    }
    return min;
}

int get_max(int arr[5], int len) {
    int max = SIGN_INT_MIN;
    for (int i = 0; i < len; ++i) {
        max = arr[i] > max ? arr[i] : max;
    }
    return max;
}

void input_arr(int arr[5], int len) {
    for (int i = 0; i < len; ++i) {
        start:
        printf("请输入第 %d 个整数: ", i + 1);
        int flag = scanf("%d", &arr[i]);
        flush();
        if (flag != 1) {
            printf("输入错误, 请重新输入!\n");
            goto start;
        }
    }
}