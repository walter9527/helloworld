#include <stdio.h>

int main(void)
{
    int cnt = 0;

    int c;
    while ((c = getchar()) != EOF) {
        printf("%c\n", c);
        cnt++;
    }

    printf("字符数: %d\n", cnt);
}
