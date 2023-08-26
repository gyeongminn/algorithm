#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

#define ll long long
#define endl '\n'
using namespace std;

int N, M;
int A[1111][1111];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for (int r = 1; r <= N; ++r) {
        for (int c = 1; c <= N; ++c) {
            cin >> A[r][c];
        }
    }

    for (int r = 1; r <= N; ++r) {
        for (int c = 1; c <= N; ++c) {
            A[r][c] += A[r - 1][c];
        }
    }
    for (int r = 1; r <= N; ++r) {
        for (int c = 1; c <= N; ++c) {
            A[r][c] += A[r][c - 1];
        }
    }

    for (int i = 0; i < M; ++i) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << A[y2][x2] - A[y1 - 1][x2] - A[y2][x1 - 1] + A[y1 - 1][x1 - 1] << endl;
    }
    return 0;
}