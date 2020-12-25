#include "common.h"

#if 0

#define stu_print(p) printf("%s = [num = %d, name = %s, age = %d]\n", #p , p.num, p.name, p.age)

typedef struct stu {
    int num;
    char name[16];
    int age;
} STU;

void test01() {
    // 普通结构体用.
    STU lucy = {100, "lucy", 20};

    STU *p = &lucy;
    printf("(*p).name = %s\n", (*p).name);;

    // 如果地址, 就用->
    printf("p->name = %s\n", p->name);

    printf("(&lucy)->name = %s\n", (&lucy)->name);
}


void test02() {
    STU *p = NULL;
    p = calloc(1, sizeof(STU));
    if (p == NULL) {
        perror("calloc err");
        return;
    }

    printf("请输入一个学生的信息!\n");
    scanf("%d %s %d", &p->num, p->name, &p->age);

    stu_print((*p));

    if (p != NULL) {
        free(p);
        p = NULL;
    }
}

void fun(STU *p) {
    printf("请输入学生的信息!\n");
    scanf("%d %s %d", &p->num, p->name, &p->age);
}

void print(const STU *p) {
    printf("[num = %d, name = %s, age = %d]\n", p->num, p->name, p->age);
}

void test03() {
    STU lucy;
    memset(&lucy, 0, sizeof(lucy));

    fun(&lucy);
    print(&lucy);
}

void print_struct_array(const STU *p, int len) {
    for (int i = 0; i < len; ++i) {
        print(p + i);
    }
}

void gets_struct_array(STU *stu, int len) {
    printf("请输入 %d 个学生信息\n", len);

    for (int i = 0; i < len; ++i) {
        printf("第 %d 个学生: ", i + 1);
        scanf("%d %s %d", &stu->num, stu->name, &stu->age);
        stu++;
    }

}

void test04() {
    int len = 5;
    STU *stu = NULL;
    stu = calloc(len, sizeof(STU));

    is_get_mem(stu);

    gets_struct_array(stu, len);

    print_struct_array(stu, len);

    mem_free((void **) &stu);
}
struct data {
    char c;
    int i;
};
void test05() {
    // 结构体大小 >= 成员大小之和
    printf("sizeof(struct data) = %lu\n", sizeof(struct data)); // 8
    struct data d;
    printf("&d.c = %u\n", &d.c); // 901492096
    printf("&d.i = %u\n", &d.i); // 901492100
}
typedef struct {
    int a;
    char b;
    short c;
    char d;
} DATA;
void test06() {
    printf("sizeof(DATA) = %lu\n", sizeof(DATA));
}

typedef struct {
    int x;
    int y;
} DATA2;

typedef struct {
    int a;
    int b;
    DATA2 c; // 结构体变量c作为 DATA3 的成员, 叫做结构体嵌套结构体
} DATA3;

void test07() {
    printf("sizeof(DATA3) = %lu\n", sizeof(DATA3)); // 16

//    DATA3 s = {1, 2, 9, 8}; // 这种也可以, 但是看不出层次
    DATA3 s = {1, 2, {9, 8}}; // 推荐初始化方式
    printf("s.a = %d\n", s.a);
    printf("s.b = %d\n", s.b);
    printf("s.c.x = %d\n", s.c.x);
    printf("s.c.y = %d\n", s.c.y);
}

typedef struct {
    short d;
    char e;
} DATA2;

typedef struct {
    short a;
    int b;
    DATA2 c;
    char f;
} DATA3;

void test08() {
    printf("sizeof(DATA3) = %lu\n", sizeof(DATA3));
    DATA3 d;
    printf("&d.a = %lu\n", &d.a);
    printf("&d.b = %lu\n", &d.b);
    printf("&d.c = %lu\n", &d.c);
    printf("&d.c.d = %lu\n", &d.c.d);
    printf("&d.c.e = %lu\n", &d.c.e);
    printf("&d.f = %lu\n", &d.f);
}

typedef struct {
    short d;
    char e;
} B;

typedef struct {
    int a;
    short b;
    B c;
    short f;
} A;

#endif

typedef struct {
    char a;
    int b;
    short c;
} DATA;

void test08() {
    DATA a = {'s', 10, 2};

    char *p = &a;
    printf("*p = %c\n", *p); // a
    printf("*(p + 4) = %d\n", *(int *)(p + 4)); // b
    printf("*(p + 8) = %hd\n", *(short *)(p + 8)); // c
}

int main(int argc, char *argv[]) {
    test08();
    return 0;
}