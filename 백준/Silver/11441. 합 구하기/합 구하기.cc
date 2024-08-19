#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> prefix_sum;

void solve() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int l, r;
        cin >> l >> r;
        cout << prefix_sum[r] - prefix_sum[l - 1] << '\n';
    }
}

void input() {
    cin >> N;
    prefix_sum.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> prefix_sum[i];
        prefix_sum[i] += prefix_sum[i - 1];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}