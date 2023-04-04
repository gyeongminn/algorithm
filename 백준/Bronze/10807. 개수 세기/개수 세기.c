#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[100]; // arr이라는 int형 배열을 생성하는데 크기는 100이다.

int main(void) {
    int n, v, count = 0;        // int형 변수 n, v를 생성한다.
    scanf("%d", &n);            // n을 입력받는다.
    for (int i = 0; i < n; i++) // 0~n-1번 반복한다
    {
        scanf("%d", &(arr[i])); // arr[i]에 입력받은걸 저장한다.
    }
    scanf("%d", &v); // v를 입력받는다.

    for (int i = 0; i < n; i++) {
        if (arr[i] == v) {
            count++;
        }
    }
    printf("%d", count);
}