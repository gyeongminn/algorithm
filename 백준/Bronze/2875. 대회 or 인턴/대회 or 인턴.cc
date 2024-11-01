#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int ans = 0;
    while (n >= 2 && m >= 1 && m + n - 3 >= k) {
        n -= 2;
        m -= 1;
        ans++;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}