#include <stdio.h>

long long nC2(int n)
{
    return (long long)n * (n - 1) / 2;
}

int main()
{
    int n;
    scanf("%d", &n);

    int root2leaf = n - 1;
    long long leaf2leaf = 2 * nC2(n - 1);
    long long sum = root2leaf + leaf2leaf;
    printf("%lld\n", sum);

    for (int i = 1; i < n; i++) {
        printf("1 %d\n", i + 1);
    }

    return 0;
}