#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, v;
    unordered_set<int> s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v;
        s.insert(v);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> v;
        cout << s.contains(v) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
