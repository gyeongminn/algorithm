#include <bits/stdc++.h>
using namespace std;

int rev(int n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stoi(s);
}

void solve() {
    int x, y;
    cin >> x >> y;
    cout << rev(rev(x) + rev(y));
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}