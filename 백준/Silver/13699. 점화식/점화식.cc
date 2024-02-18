#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull cache[36];

ull dp(int n) {
    if (n < 2) return 1;
    ull &ret = cache[n];
    if (ret != 0) return ret;

    for (int i = 0; i < n; i++) {
        ret += dp(i) * dp(n - i - 1);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    cout << dp(n);
    return 0;
}