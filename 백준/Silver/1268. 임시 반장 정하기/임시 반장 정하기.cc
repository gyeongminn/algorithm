#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> v;
vector<set<int>> s;

void solve() {
    for (int k = 0; k < 5; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (v[i][k] == v[j][k]) {
                    s[i].insert(j);
                    s[j].insert(i);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (s[ans].size() < s[i].size()) ans = i;
    }
    cout << ans + 1;
}

void input() {
    cin >> N;
    s.resize(N);
    v.resize(N);
    for (int i = 0; i < N; ++i) {
        v[i].resize(5);
        for (int j = 0; j < 5; ++j) {
            cin >> v[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}