#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> v(10);
    for (auto &item : v) cin >> item;
    nth_element(v.begin(), v.begin() + 2, v.end(), greater<>());
    cout << v[2] << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}