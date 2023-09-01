#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, M, K;
int A[100][100], B[100][100], C[100][100];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> A[i][j];
    cin >> M >> K;
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < K; ++j)
            cin >> B[i][j];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            int val = 0;
            for (int k = 0; k < M; ++k) val += A[i][k] * B[k][j];
            cout << val << ' ';
        }
        cout << endl;
    }
    return 0;
}