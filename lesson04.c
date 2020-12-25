#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 清空控制台缓存
void flush() {
    for (int ch = getchar(); ch != '\n' && ch != EOF; ch = getchar());
}


// 交换数组中 i 位置 和 j 位置的变量
int swapInt(int *arr, int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    return 1;
}

// 交换数组中 i 位置 和 j 位置的变量
int swapChar(char arr[], int i, int j)
{
    char tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    return 1;
}

void test01()
{
    /* 全部初始化, 元素个数可以省略 */
//    int arr[] = {2, 34, 5, 9, 8};
    /* 如果只初始化一部分, 剩下补零 */
    int arr[10] = {2, 34, 5, 9, 8};

    // 将所有元素清零
    int abc[10] = {0};
    for (int i = 0; i < (sizeof(abc) / 4); ++i) {
        printf("%d ==> %d\n", i, abc[i]);
    }
    printf("\n");
}

void test02()
{
    int arr[5] = {[2] = 3, [4] = 7}; // 第二个元素初始化为 3, 第四个元素初始化为 7
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; ++i) {
        printf("%d ==> %d\n", i, arr[i]);
    }
}

void test03()
{
    int arr[] = {[5] = 87};
    int len = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < len; ++i) {
        printf("%d ==> %d\n", i, arr[i]);
    }
}

#define MAX_SIGNED_INT ~(1 << 31)
#define MIN_SIGNED_INT 1 << 31

void test04()
{
    int arr[5] = {0};
    int len = sizeof(arr) / sizeof(arr[0]);
    int max = MIN_SIGNED_INT;
    int min = MAX_SIGNED_INT;
    int sum = 0;

    for (int i = 0; i < len; ++i) {
        contn:
        printf("请输入第 %d 个数字: ", i + 1);
        int flag = scanf("%d", &arr[i]);
//        flush();
        if (flag != 1) {
            printf("输入错误!\n");
            goto contn;
        }
        max = arr[i] > max ? arr[i] : max;
        min = arr[i] < min ? arr[i] : min;
        sum += arr[i];
    }

    printf("\n输入结束\n\n");

    printf("最大值 ==> %d\n", max);
    printf("最小值 ==> %d\n", min);
    printf("平均值 ==> %d\n", sum / len);

    for (int i = 0; i < len; ++i) {
        printf("%d ==> %d\n", i, arr[i]);
    }
}

void test05()
{
    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    // 分段初始化: 放满一行, 再放下一行
    int abc[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9};



}

// 二维数组
void test06() {
    int arr[3][4] = {0};

    for (int i = 0; i < 12; ++i) {
        start:
        printf("请输入第 %d 行, 第 %d 列数字: ", i / 4 + 1, i % 4 + 1);
        int flag = scanf("%d", &arr[i / 4][i % 4]);

        flush();

        if (flag != 1) {
            printf("出入错误, 请重新输入!\n");
            goto start;
        }
    }

//    srand((unsigned) time(NULL));
//    for (int i = 0; i < 12; ++i) {
//        arr[i / 4][i % 4] = rand() % 100;
//    }

    for (int i = 0, sum = 0; i < 12; ++i) {
        int element = arr[i / 4][i % 4];
        sum += element;
        printf("%-5d", element);
        if (i % 4 == 3) {
            printf("平均值: %d\n", sum / 4);
            sum = 0;
        }
    }
}

// 字符串和字符数组的区别
void test07()
{
    char str1[] = {'h', 'e', 'h', 'e'}; // 逐个字符初始化, 系统不会添加 '\0'
    char str2[] = "yaya"; // 字符串初始化, 系统会给字符串添加'\0'
    char str3[4] = "wawa";

    // 空间大小
    printf("str1 ==> %lu\n", sizeof(str1));
    printf("str2 ==> %lu\n", sizeof(str2));
    printf("str3 ==> %lu\n", sizeof(str3));

    // %s 输出内容, 遇到 '\0' 为止
    printf("str1 = ##%s##\n", str1);
    printf("str2 = ##%s##\n", str2);
    printf("str3 = ##%s##\n", str3);
}

void test08()
{
    char buf[10] = "";
//    for (int i = 0; i < 128; ++i) {
//        buf[i] = 100;
//    }
    printf("请输入一个字符串\n");
//    scanf("%s", buf); // 注意: 遇到空格会结束输入

//    gets(buf); // 获取键盘输入时, 不会管 buf 的大小, 会造成越界, 污染后面的内存空间
//    dasj79 90aj, 	ksa d
    fgets(buf, sizeof(buf), stdin); // 收录换行, 末尾加0, 因此只读取 18 个字符

    for (int i = 0; i < 30; ++i) {
        printf("%d ==> %d\n", i, buf[i]);
    }

    printf("buf = %s\n", buf);
}

void test09()
{

    char buf[128] = "";

    printf("请输入一个字符串:\n");

    fgets(buf, sizeof(buf), stdin);

    for (int i = 0; buf[i]; ++i) {
        char ch = buf[i];
        printf("%c", ch >= 'A' && ch <= 'Z' ? ch + ('a' - 'A') : ch >= 'a' && ch <= 'z' ? ch - ('a' - 'A') : ch);
    }

}

// 一维数组用于存放多个字符
// 多维数组用于存放多个字符串, 每个字符串占一行
void test10()
{
    char str[4][16] = {""};

    char tmp[128] = "";
    fgets(tmp, sizeof(tmp), stdin);

    for (int i = 0, j = 0, k= 0; tmp[i]; ++i) {
        if (tmp[i] != ' ') {
            str[j][k++] = tmp[i];
        } else {
            str[j++][k] = 0;
            k = 0;
        }
    }

    for (int i = 0; i < 4; ++i) {
        printf("%s\n", str[i]);
    }
}

void test11()
{
    int arr[10] = {0};
    printf("请输入10个整型数字\n");
    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i) {
        start:
        printf("请输入第 %d 个整型数据==>:", i + 1);
        int flag = scanf("%d", &arr[i]);
        flush();
        if (flag != 1) {
            printf("输入错误, 请重新输入!\n");
            goto start;
        }
    }

    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    for (int i = 1; i < sizeof(arr) / sizeof(int); ++i) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1] && swapInt(arr, j, j - 1); --j);
    }

    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void test12()
{
    char str[128] = {0};
    printf("请输入字符串\n");

    fgets(str, sizeof(str), stdin);

    printf("%s\n", str);

    for (int i = 1; i < sizeof(str) && str[i] != 0; ++i) {
        for (int j = i; j > 0 && str[j] > str[j - 1] && swapChar(str, j, j - 1); j--);
    }

    printf("%s\n", str);
}

int main(int argc, char *argv[])
{
    test12();

    return 0;
}