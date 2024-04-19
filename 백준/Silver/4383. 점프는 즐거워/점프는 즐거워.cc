#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) exit(0);
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    vector<bool> chk(n, false);
    for (int i = 1; i < n; ++i) {
        int diff = abs(v[i] - v[i - 1]);
        if (diff <= 0 || diff >= n || chk[diff]) break;
        chk[diff] = true;
    }

    for (int i = 1; i < n; ++i) {
        if (!chk[i]) {
            cout << "Not jolly\n";
            return;
        }
    }

    cout << "Jolly\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    while (!cin.eof()) solve();
}