#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, P;
    cin >> N >> P;

    vector<int> v;

    int cur = N;
    while (true) {
        int next = cur * N % P;

        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == next) {
                cout << v.size() - i;
                return;
            }
        }

        v.push_back(next);
        cur = next;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}