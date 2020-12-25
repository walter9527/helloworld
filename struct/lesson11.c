#include "common.h"

#define stu_print(p) printf("%s = [num = %d, name = %s, age = %d]\n", #p , p.num, p.name, p.age)

struct stu {
    int num;
    char name[32];
    int age;
};

void print_int_array(const int *arr, int len);

#if 0
void test01() {
    struct stu lucy; // 局部变量, 内容不确定

    // 通过结构体变量访问结构体中的成员
    printf("lucy.num = %d\n", lucy.num);
    printf("lucy.name = %s\n", lucy.name);
    printf("lucy.age = %d\n", lucy.age);

    char *p = lucy.name;

    lucy.num = 100;
//    lucy.name = "酒中仙"; // err
//    strcpy(lucy.name, "酒中仙");
//    sscanf("酒中仙", "%s", lucy.name);
    sprintf(lucy.name, "%s", "酒中仙");
    lucy.age = 20;


    printf("lucy.num = %d\n", lucy.num);
    printf("lucy.name = %s\n", lucy.name);
    printf("lucy.age = %d\n", lucy.age);
}

#endif
void test02() {
    // 初始化顺序, 必须与结构体成员的顺序一种
    struct stu lucy = {10, "lucy", 20};

    // 清空结构体变量
    memset(&lucy, 0, sizeof(lucy));

    stu_print(lucy);
}

void test03() {
    struct stu lucy;
    memset(&lucy, 0, sizeof(lucy));

    start:
    printf("请输入num, name, age:");
    int flag = scanf("%d %s %d", &lucy.num, lucy.name, &lucy.age);

    if (flag == 3) {
        stu_print(lucy);
    } else {
        printf("输入错误!\n");
        goto start;
    }
}

void test04() {
    struct stu lucy = {100, "小法", 18};
    struct stu bob;
    memset(&bob, 0, sizeof(bob));

    // 方法一, 推荐
    bob = lucy;
    stu_print(bob);

    memset(&bob, 0, sizeof(bob));
    split_line();

    // 方法二
    bob.num = lucy.num;
    strcpy(bob.name, lucy.name);
    bob.age = lucy.age;
    stu_print(bob);

    memset(&bob, 0, sizeof(bob));
    split_line();

    // 方法三
    memcpy(&bob, &lucy, sizeof(lucy));
    stu_print(bob);
}

void test05() {
    struct stu arr[5];
    memset(arr, 0, sizeof(arr));

    int len = sizeof(arr) / sizeof(arr[0]);

    printf("请输入 %d 个用户!\n", len);

    for (int i = 0; i < len; ++i) {
        start:
        printf("请输入第 %d 个数据: ", i + 1);
        int flag = scanf("%d %s %d", &arr[i].num, arr[i].name, &arr[i].age);
        flush();
        if (flag != 3) {
           printf("输入错误, 请重新输入!\n");
           goto start;
        }
    }

    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += arr[i].age;
        stu_print(arr[i]);
    }

    printf("avg_age = %lf\n", sum * 1.0 / len);
}

void swap(int *p, int i, int j) {
    int tmp = p[i];
    p[i] = p[j];
    p[j] = tmp;
}

void print_int_array(const int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void test06() {
    int len = 10;
    int *p = calloc(len, sizeof(int));

    if (p == NULL) {
        perror("calloc");
        return;
    }
    int *arr = p;
    for (int i = 0; i < len; ++i) {
        p[i] = rand() % 100;
    }

    print_int_array(p, len);

    for (int i = 1; i < len; ++i) {
        for (int j = i; j > 0 && p[j] < p[j - 1]; --j) {
            swap(p, j, j - 1);
        }
    }

    print_int_array(arr, len);

    if (p != NULL) {
        free(p);
        p = NULL;
    }
}


int main(int argc, char *argv[]) {
    test06();
    return 0;
}