#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int res = stoi(a) + stoi(b);
    string ans = to_string(res);
    reverse(ans.begin(), ans.end());
    cout << stoi(ans);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}