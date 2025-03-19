#include <stdio.h>

int main()
{
    int min = 1000000, max = 2;
    int count;
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        int num;
        scanf("%d", &num);

        if (num < min) {
            min = num;
        }
        if (num > max) {
            max = num;
        }
    }

    printf("%d", min * max);

    return 0;
}