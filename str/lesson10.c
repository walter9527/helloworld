#include "common.h"

// 模拟 strlen
size_t my_strlen(const char *p) {
    size_t len = 0;
    while (*(p++) != '\0') {
        len++;
    }
    return len;
}


// 模拟 strcpy
char *my_strcpy(char *dst, const char *src) {
    char *result = dst;
    while ((*dst++ = *src++));
    return result;
}

// 模拟 strncpy
char *my_strncpy(char *dst, const char *src, size_t size) {
    char *result = dst;
    while (size-- && *src && (*dst++ = *src++));
    return result;
}

// 模拟 strcat
char *my_strcat(char *dst, const char *src) {

    char *tmp = dst;
    for (; *tmp != '\0'; tmp++);

    my_strcpy(tmp, src);

    return dst;
}

// 模拟 strncat
char *my_strncat(char *dst, const char *src, size_t n) {
    char *tmp = dst;
    for (; *tmp != '\0'; tmp++);
    my_strncpy(tmp, src, n);
    return dst;
}

// 模拟 strcmp
int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && *s2 && *s1 == *s2 && s1++ && s2++);
    return (unsigned short) *s1 - (unsigned short) *s2;
}

// 模拟 strncmp
int my_strncmp(const char *s1, const char *s2, size_t n) {
    while (n-- && *s1 && *s2 && *s1 == *s2 && s1++ && s2++);
    return n ? (unsigned short) *s1 - (unsigned short) *s2 : 0;
}

// 模拟 strchr
char *my_strchr(const char *s, int c) {
    while (*s != c && *s && s++);
    return *s == c ? (char *) s : NULL;
}

// 模拟 strstr
char *my_strstr(const char *s1, const char *s2) {
    int len = my_strlen(s2);

    do {
        s1 = my_strchr(s1, *s2);
    } while (s1 != NULL && my_strncmp(s1, s2, len) && s1++);

    return (char *) s1;
}

// 模拟 memset
void *my_memset(void *s, int c, size_t n) {
    char *str = s;
    while (n-- && (*str++ = (char) c));
    return s;
}


// 模拟 atoi
int my_atoi(const char *str) {
    int flag = *str == '-' && str++ ? -1 : 1;

    int result = 0;
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str++ - '0');
    }
    return result * flag;
}

// 模拟 atol
long my_atol(const char *str) {
    int flag = *str == '-' && str++ ? 1 : -1;

    long result = 0;
    while (*str >= '0' && *str <= '9' && result <= 0) {
        result = result * 10 - (*str++ - '0');
    }

    result = result > 0 || result == SIGNED_LONG_MIN ? flag < 0 ? SIGNED_LONG_MAX : SIGNED_LONG_MIN : result * flag;
    return result;
}

double fun(const char *s) {
    if (!(*s >= '0' && *s <= '9')) {
        return 0;
    } else {
        return (*s - '0') + fun(s + 1) / 10;
    }
}

// 模拟 atof
double my_atof(const char *str) {
    int flag = *str == '-' && str++ ? -1 : 1;

    double result = 0;
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str++ - '0');
    }

    double f = 0;
    if (*str++ == '.') {
        double f = fun(str) / 10;
        result += f;
#if 0
        double b = 1;
        int n = 18;
        while (*str >= '0' && *str <= '9' && n--) {
            f = f * 10 + (*str++ - '0');
            b *= 10;
        }
        result += f / b;
#endif
    }

    return result * flag;
}

#if 0
void test01() {
    char buf1[128] = "hehehe";
    char buf2[] = "hehehe";
    char buf3[] = "hehe\0he";
    char buf4[6] = "hehe\0he";
    char buf5[] = "hehe\123\\he";
    char buf6[] = "\0hehe\0hehe";

    size_t (*p)(const char *) = NULL;

//    p = strlen;
    p = my_strlen;

    printf("%lu\n", sizeof(buf1)); // 128
    printf("%lu\n", p(buf1)); // 6

    printf("%lu\n", sizeof(buf2)); // 7 字符串后面默认添加\0
    printf("%lu\n", p(buf2)); // 6

    printf("%lu\n", sizeof(buf3)); // 8
    printf("%lu\n", p(buf3)); // 4

    printf("%lu\n", sizeof(buf4)); // 6
    printf("%lu\n", p(buf4)); // 4

    printf("%lu\n", sizeof(buf5)); // 9
    printf("%lu\n", p(buf5)); // 8

    printf("%lu\n", sizeof(buf6)); // 11
    printf("%lu\n", p(buf6)); // 0
}

void test02() {
    char src[] = "hello string";

    char dst[5] = "";

    char *(*p)(char *, char *) = NULL;
    p = strcpy;
//    p = my_strcpy;
    p(dst, src);

    printf("%s\n", dst);
}

void test03() {
    char src[] = "hello string";

    char dst[128] = "";

    char *(*p)(char *, const char *, size_t) = NULL;

//    p = strncpy;
    p = my_strncpy;
    p(dst, src, 3);

    printf("%s\n", dst);
}

void test04() {
    char src[] = "string";
    char dst[128] = "hello ";

    char *(*p)(char *, const char *, size_t n) = NULL;

//    p = strcat;
    p = my_strncat;

    p(dst, src, 3);

    printf("%s\n", dst);
}

void test05() {
    char buf0[] = "hello";
    char buf1[] = "helldas";

    printf("%d\n", my_strncmp(buf0, buf1, 4));
}



void test06() {
    char *(*f)(const char *s, int c) = NULL;
    f = my_strchr;
//    f = strchr;

    char buf[128] = "dsa\0sb";
    char *p = f(buf, '\0');

    printf("%c\n", *p);
    printf("%c\n", *++p);
}


int cnt = 0;

char *arr(char *p, int len) {
    for (int i = 0; i < len; ++i) {
        p[i] = rand() % 26 + 'a';
    }
    cnt++;
    return p;
}

void test07() {
    char buf[1281] = {0};
    char smp[] = "pussy";
    char *p = NULL;
    do {
        p = arr(buf, 1280);
    } while (my_strstr(p, smp) == NULL);

    printf("%d\n", cnt);

    do {
        p = my_strstr(p, smp);
//    } while (p != NULL && my_strncpy(p, "*****", 5));
    } while (p != NULL && memset(p, '#', 5));

    printf("%s\n", buf);
}

void test08() {
    char buf[] = "haha####hehe::::heihei@@@@lala";

#if 0
    char *arr[32] = {NULL};
    char **p = arr;

    for (*p = strtok(buf, ":"); *p++ != NULL; *p = strtok(NULL, ":"));
#endif
    char *arr[32] = {buf, NULL};
    char **p = arr;

    while ((*p = strtok(*p, ":@#")) != NULL && p++);

    p = arr;
    while (*p != NULL) {
        printf("%s\n", *p++);

    }
}
void test09() {
    int year = 2020;
    int mon = 2;
    int day = 24;

    char buf[128] = "";


    // 注意: 一个中文字符占 3 个字节
    int len = sprintf(buf, "%d年%d月%d日", year, mon, day);

    printf("%d\n", len);
    printf("%s\n", buf);
}

void test10() {
    char name[] = "张三";
    int age = 18;
    char sex[] = "男";
    char addr[] = "西藏拉萨市";

    char buf[128] = "";

    int len = sprintf(buf, "姓名: %s, 年龄: %d, 性别: %s, 地址: %s", name, age, sex, addr);

    printf("%d\n", len);
    printf("%s\n", buf);
}
void test11() {
    int num = 2020;
    char buf[128] = "";

    int len = sprintf(buf, "%d", num);

    printf("%d\n", len);
    printf("%s\n", buf);
}

void test12() {
    char buf[] = "2020年2月24日";

    int year = 0;
    int mon = 0;
    int day = 0;
    char ch = 0;
    char str_year[32] = "";
    char str_mon[32] = "";
    char str_day[32] = "";

    // 返回正确拿到数据个数
    int len = sscanf(buf, "%d年%d月%d日", &year, &mon, &day);

    // %d 只能提取 0~9
    // %c 提取一个字符
    // %f 提取浮点数

    printf("%d\n", year);
    printf("%d\n", mon);
    printf("%d\n", day);
    printf("%d\n", len);

    split_line();

    len = sscanf(buf, "%c", &ch);
    printf("%d\n", len);
    printf("%c\n", ch); // '2'

    split_line();

    // %s 提取一个字符串, 遇到空格, 回车, '\0'停止获取
    len = sscanf(buf, "%s年%s月%s日", str_year, str_mon, str_day);

    printf("%d\n", len);
    printf("%s\n", str_year); // 只提取到第一个
    printf("%s\n", str_mon); // null
    printf("%s\n", str_day); // null
}

void test13() {
    int data1 = 0;
    // 只取后半部分
//    sscanf("1234 5678", "1234 %d", &data1);
    // 跳过前面的数字
    sscanf("1234 5678", "%*d %d", &data1);
    // 用 *s 也可以
    sscanf("1234 5678", "%*s %d", &data1);

    printf("%d\n", data1);
}

void test14() {
    int data1 = 0;
    int data2 = 0;
    char buf[16] = "";

    int len = sscanf("12abc5678", "%*5s%d", &data1);

    if (len == 1) {
        printf("%d\n", data1);
    } else {
        printf("取值失败\n");
    }

    split_line();

    len = sscanf("12345678", "%*2d%2d%*2d%s", &data2, buf);

    if (len == 2) {
        printf("%d\n", data2);
        printf("%s\n", buf);
    } else {
        printf("取值失败\n");
    }

}

void test15() {
    char buf[128] = "";

    int len = sscanf("abcDefABC", "%[a-z]", buf);

    printf("%s\n", buf); // abc 直到第一个非a-z的字符
}

void test16() {
    char buf[128] = "";

    int len = sscanf("aaBBcDefABC", "%[aBc]", buf);

    printf("%s\n", buf); // aaBBc 直到遇到非aBc中的字符为止
}

void test17() {
    char buf[128] = "";

    int len = sscanf("ABCcABC", "%[^abc]", buf);

    printf("%s\n", buf); // ABC 直到遇到非aBc中的字符为止
}

void test18() {
    char name[32] = "";
    char addr[32] = "";

    sscanf("linghe@1000phone.com", "%[^@]@%[^.].com", name, addr);
//    sscanf("linghe@1000phone.com", "%[^@]%*c%[^.].com", name, addr);
//    sscanf("linghe@1000phone.com", "%[^@]%*1s%[^.].com", name, addr);

    printf("%s\n", name);
    printf("%s\n", addr);
}

void test19() {
    int m1 = 0, s1 = 0, ms1 = 0;
    int m2 = 0, s2 = 0, ms2 = 0;
    char song[128] = "";
    char buf[128] = "";

    char msg[] = "[12:13.46][8:23.45]套马杆";

    sscanf(msg, "[%d:%d.%d][%d:%d.%d]%s", &m1, &s1, &ms1, &m2, &s2, &ms2, song);

    printf("%d:%d\n", m1, s1);
    printf("%d:%d\n", m2, s2);

    printf("%s\n", song);

    sprintf(buf, "[%d:%d.%d][%d:%d.%d]%s", m1, s1, ms1, m2, s2, ms2, song);
    printf("%s\n", buf);

}
void test20() {
    // const 修饰成只读变量
    const int num = 10;

    printf("%d\n", num);

//    num++; // error

    printf("%p\n", &num);

    // 如果知道num地址, 也可以间接的修改变量的值
    // 这里必须要强转, 因为 const int 是完整的类型修饰
    *(int *)&num = 100;
    printf("%d\n", num);
}

void test21() {
    int num1 = 10;
    int num2 = 20;

    // const 在 * 左边, *p 只读, p 可读可写
    // const 修饰的是 *, 而不是 p
    const int *p = &num1;
    printf("%d\n", *p);

    int *p1 = p;
    *p1 = 1234;
    printf("%d\n", *p1);

    // 不可以通过 *p 赋值
//    *p = 100;
//    printf("%d\n", *p);

    num1 = num2;
    printf("%d\n", num1);

    // p 本身可读可写
    p = &num2;
    printf("%d\n", *p);
}

void test22() {
    int num1 = 10;
    int num2 = 20;

    int *const p = &num1;

    printf("%d\n", *p);

    *p = 1000; // *p 可读可写

    printf("%d\n", *p);

//    p = &num2; // err
}
#endif

void test23() {
    int num1 = 10;
    int num2 = 20;

    const int * const p = &num1;

//    *p = 1000; // err
//    p = &num2; // err
}

int main(int argc, char *argv[]) {
    test23();
    return 0;
}

