#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int arr[10] = {0};

    for (char c : s) {
        arr[c - '0']++;
    }

    int ans = 0;
    for (int i : arr) {
        if (i) ans++;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}