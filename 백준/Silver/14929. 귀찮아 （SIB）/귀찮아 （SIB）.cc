#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v) cin >> i;

    long long ans = 0, sum = 0;
    for (int i : v) {
        ans += sum * i;
        sum += i;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}