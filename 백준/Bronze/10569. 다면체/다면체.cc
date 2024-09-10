#include <bits/stdc++.h>
using namespace std;

void solve() {
    int v, e;
    cin >> v >> e;
    cout << 2 - v + e << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}