#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int opinion;
        scanf("%d", &opinion);

        sum += opinion;
    }

    printf("Junhee is ");
    if (sum * 2 >= n) {
        printf("cute!");
    } else {
        printf("not cute!");
    }
}