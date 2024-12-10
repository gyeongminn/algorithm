#include <bits/stdc++.h>
using namespace std;

void solve() {
    int sum = 0, minimum = INT_MAX;

    for (int i = 0; i < 7; ++i) {
        int v;
        cin >> v;

        if (v % 2) continue;

        sum += v;
        minimum = min(minimum, v);
    }

    cout << sum << ' ' << minimum << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}