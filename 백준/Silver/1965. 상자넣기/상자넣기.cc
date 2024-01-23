#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;
vector<int> dp;

void solve() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
    }
    cout << ans;
}

void input() {
    cin >> N;
    v.resize(N);
    dp.resize(N);
    for (auto &i: v) cin >> i;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}