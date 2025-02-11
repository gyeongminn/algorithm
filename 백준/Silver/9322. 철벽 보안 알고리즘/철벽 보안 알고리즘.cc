#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<string> k1(n), k2(n), ciphertext(n);
    for (auto &i : k1) cin >> i;
    for (auto &i : k2) cin >> i;
    for (auto &i : ciphertext) cin >> i;

    vector<int> indices(n, 1);
    for (int i = 0; i < k1.size(); ++i) {
        for (int j = 0; j < k2.size(); ++j) {
            if (k2[j] == k1[i]) {
                indices[i] = j;
                break;
            }
        }
    }

    for (auto &i : indices) cout << ciphertext[i] << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}