#include <bits/stdc++.h>
using namespace std;

vector<int> w(10), c(10);

void solve() {
    sort(w.begin(), w.end());
    sort(c.begin(), c.end());

    cout << w[7] + w[8] + w[9] << ' ';
    cout << c[7] + c[8] + c[9] << '\n';
}

void input() {
    for (auto &i : w) cin >> i;
    for (auto &i : c) cin >> i;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}