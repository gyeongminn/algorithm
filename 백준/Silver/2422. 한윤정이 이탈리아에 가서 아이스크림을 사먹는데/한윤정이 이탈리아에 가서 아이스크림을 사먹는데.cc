#include <bits/stdc++.h>
using namespace std;

int N, M;
bool A[300][300];

void solve() {
    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (A[i][j]) {
                for (int k = j + 1; k <= N; ++k) {
                    if (A[i][k] && A[j][k]) cnt++;
                }
            }
        }
    }
    cout << cnt;
}

int main() {
    memset(A, true, sizeof(bool) * 300 * 300);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        A[a][b] = false;
        A[b][a] = false;
    }
    solve();
    return 0;
}