#include <stdio.h>
#include <string.h>

char arr[1000000];

int main() {
    int len, i, n = 0;
    scanf("%[^\n]", arr);
    len = strlen(arr);

    for (i = 0; i < len - 2; i++)
        if (arr[i] != ' ')
            if (arr[i + 1] == ' ')
                if (arr[i + 2] != ' ')
                    n++;
    if (len == 1) {
        if (arr[0] == ' ') {
            printf("0\n");
        } else
            printf("%d\n", n + 1);
    } else
        printf("%d\n", n + 1);
}