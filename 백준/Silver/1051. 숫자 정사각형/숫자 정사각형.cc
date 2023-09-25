#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define endl '\n'
using namespace std;

int N, M;
int A[50][50];

int solve() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 50; k++) {
                if (i + k >= N || j + k >= M)
                    continue;
                int val = A[i][j];
                if (val != A[i][j + k] || val != A[i + k][j] || val != A[i + k][j + k])
                    continue;
                ret = max(ret, (k + 1) * (k + 1));
            }
        }
    }
    return ret;
}

int main(void) {
    fastio;
    cin >> N >> M;
    for (int r = 0; r < N; r++) {
        string s;
        cin >> s;
        for (int c = 0; c < s.length(); c++) {
            char tmp = s[c];
            A[r][c] = tmp - '0';
        }
    }
    cout << solve();
}