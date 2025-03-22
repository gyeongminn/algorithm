#include <stdio.h>
#define ABS(n) (n > 0 ? n : -n)

void bubble_sort(int arr[])
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int is_ap(const int arr[])
{
    int sorted_arr[4];
    for (int i = 0; i < 4; i++) {
        sorted_arr[i] = arr[i];
    }
    bubble_sort(sorted_arr);

    int diff = sorted_arr[1] - sorted_arr[0];
    for (int i = 0; i < 3; i++) {
        if (sorted_arr[i] + diff != sorted_arr[i + 1]) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int arr[4];
    for (int i = 0; i < 3; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 200; i >= -200; i--) {
        arr[3] = i;
        if (is_ap(arr)) {
            printf("%d", i);
            return 0;
        }
    }

    return 0;
}