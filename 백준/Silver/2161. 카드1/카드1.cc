#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    deque<int> d;
    for (int i = 0; i < n; ++i) {
        d.push_back(i + 1);
    }

    while (!d.empty()) {
        cout << d.front() << ' ';
        d.pop_front();

        d.push_back(d.front());
        d.pop_front();
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}