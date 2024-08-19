#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    unordered_set<string> set;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        reverse(s.begin(), s.end());
        set.insert(s);

        reverse(s.begin(), s.end());

        if (set.contains(s)) {
            cout << s.length() << ' ' << s[s.length() / 2];
        }

        set.insert(s);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}