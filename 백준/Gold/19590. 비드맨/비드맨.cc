#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull N;
vector<ull> A;
ull SUM;
ull MAX;

void solve() {
    ull ans = MAX - (SUM - MAX);
    if (MAX < (SUM - MAX)) ans = SUM % 2;
    cout << ans;
}

void input() {
    cin >> N;
    A.resize(N);
    for (auto &i : A) {
        cin >> i;
        SUM += i;
        MAX = max(MAX, i);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}