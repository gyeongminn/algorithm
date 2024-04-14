#include <bits/stdc++.h>
using namespace std;

string solve() {
    vector<int> v(3);
    for (auto &i : v) cin >> i;
    sort(v.begin(), v.end());
    if (v[0] * v[0] + v[1] * v[1] == v[2] * v[2]) return "yes";
    else return "no";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Scenario #" << i + 1 << ":\n";
        cout << solve() << "\n\n";
    }
    return 0;
}