#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;

void solve() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<vector<int>> v((int) 'z' + 1);
    int len = (int) s.length();
    for (int i = 0; i < len; ++i) {
        v[s[i]].push_back(i);
    }
    int min_len = INT_MAX;
    int max_len = INT_MIN;
    for (char c = 'a'; c <= 'z'; ++c) {
        for (int start = 0, end = k - 1; end < v[c].size(); ++end, start++) {
            min_len = min(min_len, v[c][end] - v[c][start] + 1);
            max_len = max(max_len, v[c][end] - v[c][start] + 1);
        }
    }
    if (min_len == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_len << ' ' << max_len << endl;
    }
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}