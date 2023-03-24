#include <bits/stdc++.h>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

constexpr int MOD = 10'007;
int dp[1001];

int main(void) {
    fastio;
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    cout << dp[n];
}