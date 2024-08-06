#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> v(4);
    for (auto &i : v)cin >> i;

    sort(v.begin(), v.end());
    cout << v[0] * v[2];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}