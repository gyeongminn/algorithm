#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> v(3);
    for (auto &i : v)cin >> i;

    string s;
    cin >> s;

    sort(v.begin(), v.end());
    for (auto c : s) cout << v[c - 'A'] << ' ';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}