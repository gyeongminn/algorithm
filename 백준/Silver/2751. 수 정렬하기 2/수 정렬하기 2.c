#include <stdio.h>
#define MAX_ABS_SIZE 1000000

int count[2 * MAX_ABS_SIZE + 1];

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        int index = value + MAX_ABS_SIZE;
        count[index]++;
    }

    for (int index = 0; index <= 2 * MAX_ABS_SIZE + 1; index++) {
        if (count[index]) {
            int value = index - MAX_ABS_SIZE;
            printf("%d\n", value);
        }
    }

    return 0;
}