#include <bits/stdc++.h>
using namespace std;

void solve() {
    int r, e, c;
    cin >> r >> e >> c;
    if (r < e - c) {
        cout << "advertise" << '\n';
    } else if (r > e - c) {
        cout << "do not advertise" << '\n';
    } else {
        cout << "does not matter" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}