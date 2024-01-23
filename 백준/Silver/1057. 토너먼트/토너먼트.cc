#include <bits/stdc++.h>
using namespace std;

int N, K, I;

void solve() {
    int cnt = 0;
    while (++cnt) {
        K -= K / 2;
        I -= I / 2;
        if (K == I) break;
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> K >> I;
    solve();
    return 0;
}