#include <bits/stdc++.h>
using namespace std;

void solve() {
    int sum = 0, mode = 0;
    vector<int> v(1001);
    for (int i = 0; i < 10; i++) {
        int n;
        cin >> n;
        sum += n;
        v[n]++;
        if (v[mode] < v[n]) mode = n;
    }

    cout << sum / 10 << '\n' << mode;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}