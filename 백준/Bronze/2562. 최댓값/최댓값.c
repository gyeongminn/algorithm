#include <stdio.h>

int main()
{
    int max_value = 0, max_index = 0;

    for (int i = 0; i < 9; i++) {
        int n;
        scanf("%d", &n);
        
        if (n > max_value) {
            max_value = n;
            max_index = i;
        }
    }

    printf("%d\n", max_value);
    printf("%d\n", max_index + 1);

    return 0;
}