#include "common.h"

static void encrypt_buf(char *buf, int size, unsigned int password) {
    for (int i = 0; i < size; ++i) {
        buf[i] += password;
    }
}

static void decrypt_buf(char *buf, int size, unsigned int password) {
    for (int i = 0; i < size; ++i) {
        buf[i] -= password;
    }
}

void read(char *src, char **buf, int *size) {
    FILE *src_fp = open_file(src, "r");

    fseek(src_fp, 0, SEEK_END);

    *size = ftell(src_fp);
    rewind(src_fp);

    *buf = calloc(1, *size + 1);
    is_get_mem(buf);

    // 读数据
    fread(*buf, *size, 1, src_fp);
    close_file(src_fp);
}

void save(char *dest, char *buf, int size) {
    FILE *dest_fp = open_file(dest, "w");
    fwrite(buf, size, 1, dest_fp);

    close_file(dest_fp);

    mem_free(&buf);
}

static void template(char *src, char *dest, unsigned int password, char flag) {
    char *buf = NULL;
    int size = 0;

    // 读数据
    read(src, &buf, &size);

    //开始加密解密
    if (flag == 0) {
        encrypt_buf(buf, size, password);
    } else {
        decrypt_buf(buf, size, password);
    }


    // 开始写入
    save(dest, buf, size);
}

void encrypt(char *src, char *dest, unsigned int password) {
    template(src, dest, password, 0);
}

void decrypt(char *src, char *dest, unsigned int password) {
    template(src, dest, password, 1);
}

void print_help() {
    printf("1. 加密文件\n");
    printf("2. 解密文件\n");
    printf("3. 退出\n");
}