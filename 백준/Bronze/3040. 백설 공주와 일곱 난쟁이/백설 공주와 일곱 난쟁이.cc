#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> v(9);

    int sum = 0;
    for (auto &i : v) {
        cin >> i;
        sum += i;
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            if (sum - v[i] - v[j] == 100) {
                for (int k = 0; k < 9; ++k) {
                    if (k == i || k == j)continue;
                    cout << v[k] << '\n';
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}