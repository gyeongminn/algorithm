#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;
int C;

void solve() {
    unsigned long long cnt = 0;
    for (auto &n : v) {
        if (n == 0) continue;
        cnt += ceil((double)n / C);
    }
    cout << (unsigned long long)C * cnt;
}

void input() {
    cin >> N;
    v.resize(N);
    for (auto &i : v) {
        cin >> i;
    }
    cin >> C;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}