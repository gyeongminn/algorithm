#include <bits/stdc++.h>
using namespace std;

int N, S, P;
vector<int> v;

void solve() {
    if (upper_bound(v.begin(), v.end(), -S) - v.begin() + 1 > P) {
        cout << -1;
    } else {
        cout << lower_bound(v.begin(), v.end(), -S) - v.begin() + 1;
    }
}

void input() {
    cin >> N >> S >> P;
    v.resize(N);
    for (auto &i : v) {
        cin >> i;
        i *= -1;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}