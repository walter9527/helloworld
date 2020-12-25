#include "common.h"
// 指定对齐规则
//#pragma pack (2)

#if 0
typedef struct {
    char a;
    int b;
    short c;
} DATA1;

void test01() {
    printf("sizeof(DATA1) = %lu\n", sizeof(DATA1)); // 8
}

// 位段, 一般只考虑 unsigned int 类型, 也可以考虑 unsigned char
typedef struct {
    unsigned char a: 2; // a 只占一个字节中的两位二进制
    unsigned char b: 2; // b 只占一个字节中的两位二进制
    // 相邻位段可以压缩, (压缩的位数, 不可以超过成员自身大小)
    unsigned char c: 5;
} DATA2;

void test02() {
    DATA2 data;

    // 1. 位段不可以取地址
//    printf("&data.a = %lu\n", &data.a); // error

    // 2. 位段的赋值, 不要超过位段的大小, 如果超过了, 只取位段的位数
    data.a = 6; // 110
    printf("data.a = %d\n", data.a); // 10
}

typedef struct {
    unsigned char a: 2; // a 字节后面
    unsigned char : 4; // 无意义的位段, 仅代表占据两位
    unsigned char c: 2; // c 在字节前面
} DATA3;

void test03() {
    DATA3 a = {2, 2};
    printf("a.a = %d\n", a.a);
    printf("a.c = %d\n", a.c);
    unsigned char *ch = &a;
    printf("ch = %#x\n", *ch);
    *ch = *ch >> 2;
    printf("ch = %#x\n", *ch);
}

typedef struct {
    unsigned char a: 2; // a 字节后面
    unsigned char : 0; // 另起位段, 之后的位段将在新的存储单元
    unsigned char c: 2; // c 在字节前面
} DATA4;

void test04() {
    printf("sizeof(DATA4) = %lu\n", sizeof(DATA4)); // 2
}
union data {
    char a;
    short b;
    int c;
};

void test05() {
    printf("sizeof(union data) = %lu\n", sizeof(union data));

    union data my_data;
    memset(&my_data, 0, sizeof(my_data));
    my_data.c = 0x01020304;
    my_data.b = 0x0102;
    my_data.a = 0x01;
    printf("my_data.a + my_data.b +my_data.c = %#x\n", my_data.a + my_data.b +my_data.c); // 0x01020203
}

#endif

enum POKER {
    // 列表的值, 默认从 0 开始, 后面的值默认递增
    // 元素属于符号常量, 不属于字符串, 可以直接赋值
    HONGTAO, HEITAO = 30, MEIHUA = 40, FANGKUAI
};

void test06() {
    // poker_color 的取值会四个元素的某一个
    enum POKER poker_color = HEITAO;
    // poker_color = 1000; // 不推荐, 尽量赋枚举元素的值
    printf("poker_color = %d\n", poker_color); // 1

    printf("HONGTAO = %d\n", HONGTAO); // 0
    printf("HEITAO = %d\n", HEITAO); // 30
    printf("MEIHUA = %d\n", MEIHUA); // 40
    printf("FANGKUAI = %d\n", FANGKUAI); // 41
}

int main(int argc, char *argv[]) {
    test06();
    return 0;
}