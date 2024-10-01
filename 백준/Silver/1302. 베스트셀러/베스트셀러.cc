#include <bits/stdc++.h>
using namespace std;

int N;
map<string, int> m;

void solve() {
    int max = 0;
    string answer;

    for (auto [k, v] : m) {
        if (max < v) {
            max = v;
            answer = k;
        } else if (max == v && k < answer) {
            answer = k;
        }
    }

    cout << answer;
}

void input() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        m[s]++;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}