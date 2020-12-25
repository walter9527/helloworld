//
// Created by walter on 2020/10/20.
//
#include<stdio.h>

/**
 *
 * 1. 字符串字面值可以看做字符数组
 * 2. 字符串末尾是'\0', 表示null字符
 * 3. 字符串作为右值, 将自动转为指向首元素的指针
 * 4.
 */
int main(int argc, char *argv[]) {
    //    char str[20] = "Hello, world.\n";
    //    for (int i = 0;/* str[i] != '\0'*/ i < 50; i++) {
    //        printf("%c\n", str[i]);
    //    }
    // 多维数组
    // 1. 多维数组逻辑上是三行两列数组, 物理上仍然是连续的存储
    // 2. 多维数组除了第一维可以不指定, 其他维度必须指定
    int a[3][2] = {1, 2, 3, 4, 5};

    int b[][2] = {{1, 2},
                  {3, 4},
                  {5,}
    };
    printf("%d\n", a[0][0]);
//    for (int i = 0; a[i] != '\0'; i++) {
//        printf("%d\n", a[i]);
//    }
//    for (int i = 0; b[i] != '\0'; i++) {
//        printf("%s\n", b[i]);
//    }
    return 0;
}

