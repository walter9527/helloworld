#ifndef __COMMON_H__
#define __COMMON_H__
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <string.h>

    #define LONG_SIZE sizeof(long)
    #define INT_SIZE sizeof(int)

    #define SIGNED_INT_MAX ~(1 << (INT_SIZE * 8 - 1))
    #define SIGNED_INT_MIN 1 << (INT_SIZE * 8 - 1)

    #define UNSIGNED_INT_MAX ~0
    #define UNSIGNED_INT_MIN 0

    #define SIGNED_LONG_MAX ~(1L << (LONG_SIZE * 8 - 1))
    #define SIGNED_LONG_MIN 1L << (LONG_SIZE * 8 - 1)

    #define UNSIGNED_LONG_MAX ~0L
    #define UNSIGNED_LONG_MIN 0L

    extern void flush();
    extern void split_line();
    extern void is_get_mem(void *p);
    extern void mem_free(void **p);

    extern FILE* open_file(const char *addr, const char *opt);
    extern void close_file(FILE *fp);
    extern void print_file(const char *addr);
    extern void clear_file(char *addr);
#endif

