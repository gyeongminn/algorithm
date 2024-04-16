#include <bits/stdc++.h>
using namespace std;

int cache[31];

int dp(int n) {
    if (n < 2 || n % 2) return 0;
    if (n == 2) return 3;

    int &ret = cache[n];
    if (ret != -1) return ret;

    ret = dp(n - 2) + 2;
    for (int i = 2; n - i >= 0; i += 2) {
        ret += dp(n - i) * 2;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    memset(cache, -1, sizeof(cache));

    int n;
    cin >> n;
    cout << dp(n);

    return 0;
}