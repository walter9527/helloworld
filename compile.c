#include <stdio.h>
#define N "hehe" // 仅在本文件中有效

long my_fun(int num);
long al_2(int num);

int main(int argc, char *argv[])
{
#undef N
    int num = 0;
    start:
    printf("请输入一个数字: ");
    int flag = scanf("%d", &num);
    for (char ch = getchar(); ch != '\n' && ch != EOF; ch = getchar());
    if (flag != 1) {
        printf("输入错误, 请重新输入\n");
        goto start;
    }
    long ret = my_fun(num);
    printf("ret = %ld\n", ret);
}

long my_fun(int num)
{
    if (num == 1 || num == 2) {
        return 1;
    } else {
        return my_fun(num - 1) + my_fun(num - 2);
    }
}

long al_2(int num) {
    long result = 0;
    long last_1 = 1;
    long last_2 = 1;
    for (int i = 3; i <= num; ++i) {
        result = last_1 + last_2;
        last_2 = last_1;
        last_1 = result;
    }
    return result;
}