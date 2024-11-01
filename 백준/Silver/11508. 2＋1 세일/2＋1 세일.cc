#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &i : v) cin >> i;
    sort(v.begin(), v.end(), greater<>());

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += ((i + 1) % 3) ? v[i] : 0;
    }

    cout << sum;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}