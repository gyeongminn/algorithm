#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (auto c : to_string(i + 1)) {
            for (auto t : "369") {
                if (c == t) cnt++;
            }
        }
    }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}