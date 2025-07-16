#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, n;
    scanf("%d", &n);
    scanf("%d", &x);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int current_sum = 0;
    for (int i = 0; i < x; i++) {
        current_sum += arr[i];
    }

    int max_value = current_sum, max_count = 1;
    for (int i = x; i < n; i++) {
        current_sum += arr[i] - arr[i - x];

        if (max_value < current_sum) {
            max_value = current_sum;
            max_count = 1;
        } else if (max_value == current_sum) {
            max_count++;
        }
    }

    if (max_value) {
        printf("%d\n%d", max_value, max_count);
    } else {
        printf("SAD");
    }
}