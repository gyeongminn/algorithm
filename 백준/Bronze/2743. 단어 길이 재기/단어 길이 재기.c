#include <stdio.h>

int main()
{
    char str[101];
    scanf("%s", str);

    int length = 0;
    for (char* p = str; *p; p++) {
        length++;
    }

    printf("%d", length);

    return 0;
}