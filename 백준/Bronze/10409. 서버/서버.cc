#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, T, task;
    cin >> N >> T;

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> task;
        sum += task;

        if (sum > T) {
            cout << i;
            return;
        }
    }

    cout << N;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}