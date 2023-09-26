#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

string s;

int solve() {
    int ret = 10;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) ret += 5;
        else ret += 10;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> s;
    cout << solve();
    return 0;
}