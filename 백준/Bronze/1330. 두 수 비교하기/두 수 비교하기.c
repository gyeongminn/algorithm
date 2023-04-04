#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b) {
        printf(">");
    } else if (b > a) {
        printf("<");
    } else {
        printf("==");
    }
}