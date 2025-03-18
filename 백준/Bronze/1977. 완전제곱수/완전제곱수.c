#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int sum = 0, min = 999999999;
    for (int i = 1; i * i <= 10000; i++) {
        int num = i * i;
        if (num < m || num > n) {
            continue;
        }

        sum += num;
        if (min > num) {
            min = num;
        }
    }

    if (sum == 0) {
        printf("-1");
        return 0;
    }
    
    printf("%d\n", sum);
    printf("%d\n", min);

    return 0;
}