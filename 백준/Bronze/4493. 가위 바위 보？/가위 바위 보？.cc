#include <bits/stdc++.h>
using namespace std;

void solve() {
    int p1_cnt = 0, p2_cnt = 0;

    int n;
    cin >> n;
    while (n--) {
        char p1, p2;
        cin >> p1 >> p2;

        if (p1 == p2) continue;

        // In ASCII, P < R < S
        if (p1 + p2 == 'P' + 'S') {
            if (p1 > p2) p1_cnt++;
            else p2_cnt++;
        } else {
            if (p1 < p2) p1_cnt++;
            else p2_cnt++;
        }
    }

    if (p1_cnt == p2_cnt) cout << "TIE\n";
    else cout << (p1_cnt > p2_cnt ? "Player 1" : "Player 2") << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}