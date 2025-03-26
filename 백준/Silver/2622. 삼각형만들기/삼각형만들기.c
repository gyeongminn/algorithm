#include <stdio.h>

int main() 
{
    int n;
    scanf("%d", &n);

    int count = 0;
    for (int a = 1; a < n; ++a) {
        for (int b = a; b < n; ++b) {
            int c = n - a - b;

            if (b > c) {
                break;
            }

            if (a + b > c) {
                count++;
            }
        }
    }

    printf("%d", count);
}