#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> price;
vector<int> dist;

void solve() {
    long long ans = 0;
    for (int i = 0; i < N - 1; ++i) {
        ans += price[i] * dist[i];
    }
    cout << ans;
}

void input() {
    cin >> N;

    price.resize(N - 1);
    dist.resize(N - 1);

    for (auto &i : dist) {
        cin >> i;
    }

    int cur_min = INT_MAX;
    for (auto &i : price) {
        cin >> i;
        if (i > cur_min) i = cur_min;
        else cur_min = i;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}