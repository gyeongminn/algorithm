#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define endl '\n'
using namespace std;

int main(void) {
    fastio;
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &item : v) {
        cin >> item;
    }
    vector<ll> sum(n + 1);
    sum[0] = 0;
    partial_sum(v.begin(), v.end(), sum.begin() + 1);
    ll max = -100'000'000;
    for (int i = 0; i + k <= n; i++) {
        if (max < sum[i + k] - sum[i]) {
            max = sum[i + k] - sum[i];
        }
    }
    cout << max;
}