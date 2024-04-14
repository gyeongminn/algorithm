#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int ans = 0;
    int top = 0;
    int len = 0;
    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;

        if (top > h) {
            len++;
        } else {
            top = h;
            len = 0;
        }

        ans = max(ans, len);
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}