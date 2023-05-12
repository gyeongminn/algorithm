#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define endl '\n'
#define MAX 1000000
using namespace std;

int n, k;
ll arr[MAX + 1];
ll sum[MAX + 1];

int solve() {
    if (k > MAX) {
        return sum[MAX-1];
    }
    ll ret = 0;
    for (int i = k; i <= MAX - k; i++) {
        ret = max(ret, sum[i + k] - sum[i - k - 1]);
    }
    return ret;
}

int main(void) {
    fastio;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int g, x;
        cin >> g >> x;
        arr[x] = g;
    }
    partial_sum(arr, arr + MAX, sum);
    cout << solve();
}