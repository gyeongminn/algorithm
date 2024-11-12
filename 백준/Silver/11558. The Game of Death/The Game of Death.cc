#include <bits/stdc++.h>
using namespace std;

int solve() {
    int nPlayers;
    cin >> nPlayers;

    vector<int> v(nPlayers);
    for (auto &i : v) cin >> i;

    int cur = v[0];
    vector<bool> visited(nPlayers);
    for (int i = 0; i < 10'000; ++i) {
        if (visited[cur - 1]) break;
        if (cur == nPlayers) return i + 1;

        cur = v[cur - 1];
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) cout << solve() << '\n';
    return 0;
}