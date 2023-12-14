#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v) cin >> i;
    unsigned long long ans = v.front() + v.back() * 3 + 2 * n;
    for (int i = 0; i < v.size() - 1; ++i) {
        ans += abs(v[i] - v[i + 1]) + v[i] * 2;
    }
    cout << ans;
    return 0;
}