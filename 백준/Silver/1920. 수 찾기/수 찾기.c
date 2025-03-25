#include <stdio.h>
#include <stdlib.h>

int N, M;
int A[100000];

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
      
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int binary_search(int* arr, int low, int high, int target)
{
    if (low > high) {
        return 0;
    }

    int mid = (low + high) / 2;
    if (arr[mid] == target) {
        return 1;
    } else if (arr[mid] > target) {
        return binary_search(arr, low, mid - 1, target);
    } else {
        return binary_search(arr, mid + 1, high, target);
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    merge_sort(A, 0, N - 1);

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int target;
        scanf("%d", &target);

        int result = binary_search(A, 0, N - 1, target);
        printf("%d\n", result);
    }

    return 0;
}