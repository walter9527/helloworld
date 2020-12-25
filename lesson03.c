#include <stdio.h>

void test01()
{
    int data1 = 0;
    int data2 = 0;

    // 逗号运算符的优先级最低
    data1 = 3, 4, 5, 6; // 3
    data2 = (3, 4, 5, 6); // 6
    printf("data1 = %d\n", data1);
    printf("data2 = %d\n", data2);
}

void test02()
{
    int a = 0;
    printf("请输入一个整数: \n");
    int flag = scanf("%d", &a);
    if (flag != 1) {
        printf("输入不正确!");
    } else if (a % 3 == 0 && a % 7 == 0) {
        printf("ok\n");
    } else {
        printf("no\n");
    }
}

void test03()
{
    while (1) {
        char ch = 0;
        printf("请输入你的方向: wasd\n");
        scanf("%c", &ch);
        printf("ch == %#x\n", ch);
        if (feof(stdin) || ferror(stdin)) {
            printf("###> %x ==> 输入错误! <###\n", ch);
            continue;
        }
        for (char c = getchar(); c != '\n' && c != EOF; c = getchar());
        switch (ch) {
            case 'w':
            case 'W':
                printf("###> %c ==> 上 <###\n", ch);
                break;
            case 'a':
            case 'A':
                printf("###> %c ==> 左 <###\n", ch);
                break;
            case 's':
            case 'S':
                printf("###> %c ==> 下 <###\n", ch);
                break;
            case 'd':
            case 'D':
                printf("###> %c ==> 右 <###\n", ch);
                break;
            default:
                printf("###> %c ==> 输入不正确! <###\n", ch);
                break;
        }
    }
}

void test04()
{
    while (1) {
        int data = 0;
        printf("请输入 1~7 的数字: \n");
        int flag = scanf("%d", &data);
        printf("data ==> ##%#x##\n", data);
        for (char ch = getchar(); ch != '\n' && ch != EOF; ch = getchar());
        if (flag != 1 || ferror(stdin) || feof(stdin)) {
            printf("输入错误, 请重新输入!");
            continue;
        }

        switch (data) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                printf("工作日\n");
                break;
            case 6:
            case 7:
                printf("休息日\n");
                break;
            default:
                printf("输入错误!, 请输入 1 ~ 7 的数!\n");
                break;
        }
    }

}

void test05()
{
    int i = 0;
    int sum = 0;

    while (i < 100) {
        sum += ++i;
    }

    printf("sum = %d\n", sum);
}

int main(int argc, char* argv[])
{
    test05();
//    test04();
//    char ch = 0x85; // 1000 0101
//    char ch = 0x45; // 0100 0101
//    printf("%#x\n", ch >> 4);
//    printf("%#d\n", ch >> 4);
//    printf("%u\n", ch);
//    printf("%d\n", ch);
//    printf("%x\n", ch); // 十六进制输入和无符号输出都是内存原样输出
    return 0;
}