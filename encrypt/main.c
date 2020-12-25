#include "encrypt.h"
#include "common.h"

void get_src_name(char *src_name) {
    printf("请输入要加/解密的文件: ");
    scanf("%s", src_name);
    flush();
}

void get_dest_name(char *dest_name) {
    printf("请输入输出文件: ");
    scanf("%s", dest_name);
    flush();
}

void get_password(unsigned int *password) {
    printf("请输入密码: ");
    scanf("%u", password);
    flush();
}



int main(int argc, char *argv[]) {
    while (1) {
        print_help();
            char src[64] = "";
            char dest[64] = "";
            unsigned int password = 0;

        int i = 0;
        scanf("%d", &i);

        if (i == 1 || i == 2) {
            get_src_name(src);
            get_dest_name(dest);
            get_password(&password);

            if (i == 1) {
                encrypt(src, dest, password);
            } else {
                decrypt(src, dest, password);
            }
        } else if (i == 3) {
            break;
        } else {
            printf("输入错误, 请重新输入\n");
        }
    }

    return 0;
}