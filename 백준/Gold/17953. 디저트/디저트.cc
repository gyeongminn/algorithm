#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[10][100'000];
int dp[10][100'000];

void solve() {
    for (int i = 1; i < N; ++i) { // N번째 날
        for (int j = 0; j < M; ++j) { // M^2로 모든 경우를 본다
            for (int k = 0; k < M; ++k) {
                int val = dp[k][i - 1] + ((j == k) ? A[j][i] / 2 : A[j][i]);
                dp[j][i] = max(dp[j][i], val);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) cin >> A[i][j];
        dp[i][0] = A[i][0]; // 첫 날은 전 날의 영향을 받지 않으므로 초기화시킨다
    }

    solve();

    int ans = 0;
    for (int i = 0; i < M; ++i) ans = max(ans, dp[i][N - 1]);
    cout << ans; // 디저트별 최댓값은 DP의 결과(마지막 값)와 같고, 이 중 최대를 출력

    return 0;
}