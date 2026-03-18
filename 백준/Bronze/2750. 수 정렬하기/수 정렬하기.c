#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int h, int m, int *u, int *v, int *arr) {
    int i = 0, j = 0, k = 0;
    while (i < h && j < m) {
        if (u[i] <= v[j]) {
            arr[k++] = u[i++];
        } else {
            arr[k++] = v[j++];
        }
    }
    while (j < m) arr[k++] = v[j++];
    while (i < h) arr[k++] = u[i++];
}

void mergesort(int n, int *arr) {
    if (n < 2) return;
    int h = n / 2, m = n - h;
    int *u = (int *) malloc(h * sizeof(int));
    int *v = (int *) malloc(m * sizeof(int));
    memcpy(u, arr, h * sizeof(int));
    memcpy(v, arr + h, m * sizeof(int));
    mergesort(h, u);
    mergesort(m, v);
    merge(h, m, u, v, arr);
    free(u), free(v);
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    mergesort(n, arr);
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    free(arr);
}
