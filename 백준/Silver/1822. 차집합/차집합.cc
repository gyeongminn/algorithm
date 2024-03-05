#include <bits/stdc++.h>
using namespace std;

set<int> A;

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        A.insert(val);
    }

    for (int i = 0; i < m; ++i) {
        int val;
        cin >> val;
        if (A.contains(val)) {
            A.erase(val);
        }
    }

    cout << A.size() << '\n';
    for (auto i : A) {
        cout << i << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}