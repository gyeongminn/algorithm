#include <bits/stdc++.h>
using namespace std;

int MAX_SIZE = 31;
int N, K;
int dp[31][31];

void solve() {
    fill_n(&dp[0][0], MAX_SIZE * MAX_SIZE, 1);
    for (int i = 1; i < MAX_SIZE; ++i) {
        for (int j = 1; j < i; ++j) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    cout << dp[N - 1][K - 1];
}

void input() {
    cin >> N >> K;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}