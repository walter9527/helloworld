#include <memory.h>
#include "common.h"

int get_size_input() {
    int size;
    start:
    printf("请输入数组的大小: ");
    int flag = scanf("%d", &size);
    flush();
    if (flag != 1) {
        printf("输入错误, 请重新输入!\n");
        goto start;
    }
    return size;
}

void array_print(int *p, int len) {
    printf("[");
    for (int i = 0; i < len; ++i) {
        printf("%d", *(p + i));
        if (i != len - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

#if 0
void test01() {
    int *addr = NULL;

    addr = malloc(sizeof(int));

    if (addr == NULL) { // 申请失败
        printf("malloc err\n");
        return;
    } else {            // 申请成功
        printf("%d\n", *addr); // 不确定的值
    }
    // 对堆区空间清零, 每个字节都变成97
    memset(addr, 97, sizeof(int));

    char *ch = addr;
    for (int i = 0; i < 4; ++i) {
        printf("%c\n", *(ch + i));
    }

    // 释放堆区空间, 释放使用权限
    free(addr);
}





/*
    1. 从键盘获取用户要申请的数组大小
    2. 根据大小从堆区申请空间
    3. 对空间的读写操作
    4. 释放空间
 */
void test02() {
    int size = get_size_input();

    int *p = NULL;
    p = malloc(sizeof(int) * size);

    if (p == NULL) {
        // 申请失败, 打印错误信息
        perror("malloc err\n");
        return;
    }

    // 格式化
    memset(p, 0, sizeof(int));

    for (int i = 0; i < size; ++i) {
        *(p + i) = rand() % 100;
    }

    array_print(p, size);

    // 释放空间
    free(p);
}

void test02() {
    int size = get_size_input();

    int *p = NULL;
//    p = malloc(sizeof(int) * size);
    p = calloc(size, sizeof(int));

    if (p == NULL) {
        // 申请失败, 打印错误信息
        perror("malloc err\n");
        return;
    }

    // 格式化
//    memset(p, 0, sizeof(int));

    for (int i = 0; i < size; ++i) {
        *(p + i) = rand() % 100;
    }

    array_print(p, size);

    // 释放空间
    free(p);
}

void test03() {
    int size = get_size_input();

    int *p = NULL;
    p = malloc(sizeof(int) * size);

    if (p == NULL) {
        // 申请失败, 打印错误信息
        perror("malloc err\n");
        return;
    }

    // 格式化
    memset(p, 0, sizeof(int));

    for (int i = 0; i < size; ++i) {
        *(p + i) = rand() % 100;
    }

    array_print(p, size);

    size += 20;
    p = realloc(p, size * sizeof(int));
    if (p == NULL) {
        // 申请失败, 打印错误信息
        perror("malloc err\n");
        return;
    }

    array_print(p, size);
}

#endif

void test04() {
    // 1. 指向堆区空间的指针变量, 不要随意改变指向, 否则原来的空间将被遗忘而得不到释放, 直到进程结束
    int *p = calloc(1, sizeof(int));
    free(p);

    int num = 10;

    p = &num; // p指向 num, 导致 calloc 申请的空间泄露

    // 2. 不要操作已释放的空间
    int *p2 = calloc(1, sizeof(int));
    *p2 = 1000;
    printf("%d\n", *p2);

    free(p2);

    printf("%d\n", *p2); // 不确定

    // 3. 不要对堆区空间重复释放
    int *p3 = calloc(1, sizeof(int));
    memfree(&p3);
    memfree(&p3);

}

void test05() {
    int *p = calloc(1, sizeof(int));

}
int main(void) {
    test04();
}
