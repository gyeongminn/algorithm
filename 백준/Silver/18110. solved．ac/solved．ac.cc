#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;

void solve() {
    if (N == 0) {
        cout << 0;
        return;
    }
    
    sort(v.begin(), v.end());
    int n_cut = floor(N * 0.15 + 0.5);

    int sum = 0;
    for (int i = n_cut; i < N - n_cut; ++i) {
        sum += v[i];
    }

    cout << floor((double) sum / (N - n_cut * 2) + 0.5);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    v.resize(N);
    for (auto &i: v) {
        cin >> i;
    }
    solve();
    return 0;
}