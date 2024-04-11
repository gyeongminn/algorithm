#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000000;
int N;
int cache[101][10];

int dp(int len, int n) {
    if (n < 0 || n > 9) return 0;
    if (len == N) return n > 0;

    int &ret = cache[len][n];
    if (ret != -1) return ret;

    int a = dp(len + 1, n - 1) % MOD;
    int b = dp(len + 1, n + 1) % MOD;

    return ret = (a + b) % MOD;
}

void solve() {
    cin >> N;
    memset(cache, -1, sizeof(cache));
    int ans = 0;
    for (int i = 0; i < 10; ++i) {
        ans += dp(1, i);
        ans %= MOD;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}