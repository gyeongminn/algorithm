#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;

int main(void) {
    fastio;
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) {
        cin >> i;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, v[n - i] * i);
    }
    cout << ans;
}