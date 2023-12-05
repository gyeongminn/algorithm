#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N;
ll total;
vector<pair<ll, ll>> v;

ll solve() {
    ll cur = 0;
    for (auto p : v) {
        cur += p.second;
        if (cur >= (total + 1) / 2) {
            return p.first;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    v.resize(N);
    for (auto& p : v) {
        cin >> p.first >> p.second;
        total += p.second;
    }
    sort(v.begin(), v.end());
    cout << solve();
    return 0;
}