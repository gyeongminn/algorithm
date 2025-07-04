#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    int sum = 0;
    for (int i = 0; i < M; ++i) {
        int t, r;
        cin >> t >> r;

        sum += r;

        if (sum > K) {
            cout << i + 1 << ' ' << 1;
            return 0;
        }
    }

    cout << -1;
    return 0;
}