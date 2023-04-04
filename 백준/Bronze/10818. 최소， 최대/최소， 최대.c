#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int n, num;
    int min = 1000000, max = -1000000;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (min > num) {
            min = num;
        }
        if (max < num) {
            max = num;
        }
    }
    printf("%d %d", min, max);
}