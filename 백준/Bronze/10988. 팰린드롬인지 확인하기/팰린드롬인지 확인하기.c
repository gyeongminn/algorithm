#include <stdio.h>
#include <string.h>

int main(void) {
    char s[105] = {0};
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len / 2; ++i) {
        if (s[i] != s[len - 1 - i]) {
            printf("0");
            return 0;
        }
    }
    printf("1");
    return 0;
}