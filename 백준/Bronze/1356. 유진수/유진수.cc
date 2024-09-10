#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    for (int i = 1; i < s.length(); ++i) {
        long long l = 1, r = 1;
        for (int j = 0; j < i; ++j) l *= s[j] - '0';
        for (int j = i; j < s.length(); ++j) r *= s[j] - '0';
        if (l == r) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}