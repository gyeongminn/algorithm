#include <bits/stdc++.h>
using namespace std;

int K, L;
unordered_set<string> s;
vector<string> v1;
vector<string> v2;

void solve() {
    int cnt = 0;
    for (const auto &p: v2) {
        if (cnt == K) {
            break;
        }
        cout << p << '\n';
        cnt++;
    }
}

void input() {
    cin >> K >> L;
    v1.resize(L);
    for (auto &p: v1) {
        cin >> p;
    }
    reverse(v1.begin(), v1.end());
    for (const auto &p: v1) {
        if (!s.contains(p)) {
            s.insert(p);
            v2.push_back(p);
        }
    }
    reverse(v2.begin(), v2.end());
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}