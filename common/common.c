#include <stdio.h>
#include <stdlib.h>
#include <time.h>

__attribute((constructor)) void before_main() {
    srand((unsigned) time(NULL) * 10);
}

void is_get_mem(void *p) {
    if (p == NULL) {
        perror("alloc err!\n");
        return;
    }
}

void mem_free(void **p) {
    if (*p != NULL) {
        free(*p);
        *p = NULL;
    }
}

FILE* open_file(const char *addr, const char *opt) {
    FILE *fp = NULL;
    if (!(fp = fopen(addr, opt))) {
        perror("fopen!!\n");
        exit(0);
    }
    return fp;
}

void close_file(FILE *fp) {
    if (fclose(fp) == EOF) {
        perror("fclose!!\n");
        return;
    }
}


void print_file(const char *addr) {

    FILE *fp = open_file(addr, "r");

    char buf[1024] = "";
    for (int i = 0, ch; (ch = fgetc(fp)) != EOF; i++) {
        buf[i] = ch;
    }

    printf("%s\n", buf);

    close_file(fp);
}

void clear_file(const char *addr) {
    FILE *fp = open_file(addr, "w");
}

void flush() {
    for (char ch = getchar(); ch != '\n' && ch != EOF; ch = getchar());
}

void split_line() {
    printf("==============================\n");
}
