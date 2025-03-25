#include <stdio.h>
#define LOG_2_64 6

int main()
{
    int x;
    scanf("%d", &x);

    int count = 0;
    for (int stick = 64; stick > 0; stick /= 2) {
        if (stick > x) {
            continue;
        }

        x -= stick;
        count++;
    }
    printf("%d", count);

    return 0;
}