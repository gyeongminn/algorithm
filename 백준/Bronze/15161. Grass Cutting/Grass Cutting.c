#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int A[10][10];

void grow()
{
    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            A[r][c]++;
        }
    }
}

void solve()
{
    bool visited[10][10];
    memset(visited, 0, sizeof(visited));

    for (int j = 0; j < 6; ++j) {
        int n;
        scanf("%d", &n);

        int idx = n - 1;

        for (int i = 0; i < 10; ++i) {
            int r = j < 3 ? idx : i;
            int c = j < 3 ? i : idx;

            if (visited[r][c])
                continue;

            A[r][c] = 1;
            visited[r][c] = true;
        }
    }
}

void print()
{
    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            printf("%d ", A[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int k;
    scanf("%d", &k);

    grow();
    while (k--) {
        grow();
        solve();
    }
    print();

    return 0;
}