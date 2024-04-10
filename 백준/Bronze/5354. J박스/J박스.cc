#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (r == 0 || c == 0 || r == n - 1 || c == n - 1) {
                cout << '#';
            } else {
                cout << 'J';
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}