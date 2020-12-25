#include "common.h"

#if 0
// 读操作
void test01() {

    // 1. 使用 fopen 打开一个文件 获得文件指针
    FILE *fp = fopen("../file/b.txt", "r");
    if (fp == NULL) {
        perror("fopen!\n");
        return;
    }

    char buf[128] = "";

    // 2. 对文件的操作 fgetc
    for (int i = 0, ch = 0; (ch = fgetc(fp)) != EOF; i++) {
        buf[i] = ch;
    }

    printf("buf = %s\n", buf);

    // 3. 关闭文件
    fclose(fp);
}

void test02() {
    FILE *fp = NULL;
    if (!(fp = fopen("../a.txt", "w"))) {
        perror("fopen!!\n");
        return;
    }

    printf("请输入要写入文件的字符串: ");
    char buf[128];
    fgets(buf, sizeof(buf), stdin);
    buf[sizeof(buf) - 1] = 0;

    for (int i = 0; buf[i] != 0; i++) {
        if (fputc(buf[i], fp) == EOF) {
            perror("fputc!!!\n");
            return;
        }
    }

    fclose(fp);
}

void test03() {
    FILE *a = open_file("../a.txt", "r");
    FILE *b = open_file("../file/b.txt", "w");


    for (int i = 0, ch; (ch = fgetc(a)) != EOF; i++) {
        fputc(ch, b);
    }

    close_file(a);
    close_file(b);
}

void test04() {
    FILE *fp = open_file("../c.txt", "w");

    char *arr[] = {"窗前明月光", "疑是地上霜", "举头望明月", "低头思故乡"};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        fputs(*(arr + i), fp);
        fputc('\n', fp);
    }

    close_file(fp);

    print_file("../c.txt");
}

void test05() {
    FILE *fp = open_file("../c.txt", "r");
    char buf[128] = "";
    // 按行循环读取
    while (fgets(buf, sizeof(buf), fp)) {
        printf("%s", buf);
    }
}

typedef struct {
    char name[16];
    int deff;
    int atk;
} HERO;

void test06() {
    HERO hero[] = {
            {"德玛西亚", 80, 60},
            {"盲僧",   90, 80},
            {"小法",   40, 85},
            {"小炮",   50, 90}};

    int len = sizeof(hero) / sizeof(hero[0]);

    FILE *fp = open_file("hero.txt", "w");

    // 写入数据不便于查看, 但是不影响读写
    fwrite(hero, sizeof(HERO), len, fp);

    close_file(fp);

    print_file("hero.txt");
}

void test07() {
    int len = 4;

    HERO *hero = calloc(sizeof(HERO), len);
    is_get_mem(hero);

    FILE *fp = open_file("hero.txt", "r");

    fread(hero, sizeof(HERO), len, fp);

    for (int i = 0; i < len; ++i) {
        printf("姓名: %s, 攻击: %d, 防御: %d\n", hero[i].name, hero[i].atk, hero[i].deff);
    }

    mem_free(&hero);
    close_file(fp);
}

void test08() {
    HERO hero[] = {
            {"德玛西亚", 80, 60},
            {"盲僧",   90, 80},
            {"小法",   40, 85},
            {"小炮",   50, 90}};

    int len = sizeof(hero) / sizeof(hero[0]);

    char *addr = "hero.txt";

    FILE *fp = open_file(addr, "w");

    // 适合于查看
    for (int i = 0; i < len; ++i) {
        if (fprintf(fp, "英雄: %s 防御:%d 攻击:%d\n", hero[i].name, hero[i].deff, hero[i].atk) < 0) {
            perror("fprintf err!\n");
            return;
        }
    }
    close_file(fp);

    fp = open_file(addr, "r");

    char buf[128] = "";
    while (fgets(buf, sizeof(buf), fp)) {
        printf("buf = %s", buf);
    }

    close_file(fp);
}

void test09() {
    HERO hero[4];
    int len = sizeof(hero) / sizeof(hero[0]);

    char *addr = "hero.txt";
    FILE *fp = open_file(addr, "r");

    for (int i = 0; i < len; ++i) {
        HERO h = hero[i];
        fscanf(fp, "英雄: %s 防御:%d 攻击:%d\n", h.name, &h.deff, &h.atk);
        printf("姓名: %s, 攻击: %d, 防御: %d\n", h.name, h.atk, h.deff);
    }

    close_file(fp);
}
void test10() {
    char *addr = "a.txt";
    FILE *fp = open_file(addr, "w+");

    fputs("hello world", fp);

    long file_len = ftell(fp);

    printf("file_len = %ld\n", file_len);

    close_file(fp);
}

void test11() {
    char *addr = "a.txt";
    FILE *fp = open_file(addr, "r");

    // 将文件指针定位到文件尾
    fseek(fp, 0, SEEK_END);

    // 获取文件字节数
    int len = ftell(fp);

    // 复位文件指针
    rewind(fp);

    // 申请内存, 增加一个字节是存放结束标志 \0
    char *data = calloc(1, len + 1);
    if (data == NULL) {
        close_file(fp);
        return;
    }

    // 一次性全部读入
    fread(data, len, 1, fp);

    // 打印结果
    printf("data = %s\n", data);

    printf("len = %d\n", len);

    close_file(fp);

    // 释放堆区空间
    mem_free(fp);
}

void test12() {
    FILE *fp = open_file("a.txt", "r");

    while (feof(fp) == 0) {
        char ch = fgetc(fp);
        printf("ch = %c\n", ch);
    }
}
#endif

void test13() {
    FILE *fp = open_file("a.txt", "w");

    char ch = getc(fp);

    if (ferror(fp)) {
        perror("read err!\n");
        clearerr(fp);
    }

    close_file(fp);
}

int main(int argc, char *argv[]) {
    test13();
//    clear_file("hero.txt");
    return 0;
}