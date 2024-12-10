#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> a(10), b(10);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    int sa = 0, sb = 0;
    for (int i = 0; i < 10; ++i) {
        if (a[i] == b[i]) continue;
        if (a[i] > b[i]) sa++;
        else sb++;
    }

    if (sa > sb) cout << 'A';
    else if (sa < sb) cout << 'B';
    else cout << 'D';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}