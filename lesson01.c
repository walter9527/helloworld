#include <stdio.h>

int add_fun(int a, int b) {
    return a + b;
}

void test01()
{
    int num = 100;
    // 加上 # 号表示按进制格式输出
    printf("十进制: num = %d\n", num);
    printf("八进制: num = %#o\n", num);
    printf("十六进制: num = %#x\n", num);
}

int test02()
{
    int num;
    printf("num = %d\n", num);

    num = 100;
    printf("num = %d\n", num);

    printf("请输入一个整型数据: ");
    scanf("%d", &num);
    printf("num = %d\n", num);
}

int test03()
{
    int num1 = 1;
    printf("num1 = %d\n", num1);

    unsigned int num2 = 0;
    // %u 无符号 int 输出
    printf("num2 = %u\n", num2);

    long num3 = 0;
    printf("num3 = %ld\n", num3);

    unsigned long num4 = 0;
    printf("num4 = %lu\n", num4);

    unsigned long long num5 = 0;
    printf("num5 = %llu\n", num5);

    short num6 = 0;
    printf("num6 = %hd\n", num6);

    unsigned short num7 = 0;
    printf("num7 = %hu\n", num7);
}

// 浮点型
void test04()
{
    printf("sizeof(3.14) = %llu\n", sizeof(3.14));
    printf("sizeof(3.14f) = %llu\n", sizeof(3.14f));

    float f = 3.141592653;
    printf("f = %f\n", f);

    double d = 3.141592653;
    printf("sizeof(3.141592653) = %llu\n", sizeof(3.141592653));
    printf("sizeof(d) = %llu\n", sizeof(d));
    printf("d = %.17f\n", 3.141592653);

    printf("d = %lf\n", d);

    scanf("%f", &f);
    scanf("%lf", &d);
}

// 字符型
void test05()
{
    /* C语言中, 字符常量指代该字符在 ASCII 码表中对应的整型数字 */
    /* 'a' 与 97 完全等价 */

    printf("%c\n", 'a'); // 输出字符
    printf("%d\n", 'a'); // 输出字符的 ASCII 码

    printf("char = %llu\n", sizeof('c')); // 占四个字节

    char ch = 97; // 可以直接将整型数字直接赋值给字符型变量
    int i = 'a'; // 'a' 代表 ASCII 对应的整型数值

    printf("char a = %llu\n", sizeof(ch)); // 字符型占一个字节
    printf("int i = %d\n", i); // 打印 97

    ch = ch + 1;

    printf("%c\n", ch); // 输出字符
    printf("%d\n", ch); // 输出字符的 ASCII 码
}

_Noreturn void test06()
{
    char ch;
    char ch1;
    printf("请输入一个字符: \n");
    scanf("%c%c", &ch, &ch1);
    // ch = getchar()

    printf("ch = %c\n", ch);
    printf("ch = %d\n", ch1);
}

void test07()
{
    char ch, ch1;
    char ch2;
    // 跳过中间的输入字符
//    scanf("%c%*1%c", &ch, &ch2, &ch1);
    ch = getchar();
    getchar();
    ch1 = getchar();
    printf("ch = %c\n", ch);
    printf("ch1 = %c\n", ch1);
}

void test08()
{
    printf("##%c##\n", '\\');
    printf("##>%%<##\n");

    printf("A: %d\n", '0');
    printf("B: %d\n", '\0');
    printf("C: %d\n", 0);
    printf("D: %d\n", "0"); // 字符串第零个元素的地址

}

// 字符串输出
void test09()
{
    // '' 取的是字符的 ASCII 码, "" 取的是字符串大的首元素地址
    // %s 从字符串首元素逐个输出, 直到遇到 '\0' 停止
    printf("%s\n", "hello w\0orld");
    // 系统会在字符串末尾自动添加结束字符 '\0'
    printf("%llu\n", sizeof("hello world")); // 字符串默认以 '\0' 结尾
    printf("%llu\n", sizeof("a")); // 2 个字节, 分别是 a 和 \0
    printf("%llu\n", sizeof('a')); // 4 个字节
}

// 输出格式
void test10()
{
    // 占至少 5 个终端位宽, 右对齐
    printf("##%5d##\n", 123);
    // 占至少 5 个终端位宽, 左对齐
    printf("##%-5d##\n", 123);

    // 注意: %-05d 这种写法是不合理的, 因为左对齐补零会让数字变成 12300, 改变了原来的数字
    // 实际代码中会忽略 0 的标识, 仅表示 %-5d
    printf("##%-05d##\n", 123);

    // %5.2f 两位小数, 不足会补零, 总位宽至少五位, 包括小数点
    printf("##%5.2f##\n", 3.1);
}

// typedef 为已有的类型取别名
typedef int INT32;
void test11()
{
    double x = 1;
    double y = x + 3 / 2;
    printf("y = %lf\n", y);
}

void test12()
{
    int a = 1 + 'a';
    printf("a = %d\n", a);

    printf("double = %llu\n", sizeof(double));
    printf("double = %llu\n", sizeof(long));
}

int main(int argc, char *argv[])
{
    test12();
    return 0;
}
