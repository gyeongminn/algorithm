#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

void solve() {
    ull n; cin >> n;

    ull ans = 0;
    for (ull i = 1; i < n; ++i) {
        ans += i * n + i;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}