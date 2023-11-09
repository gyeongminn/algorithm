#include <bits/stdc++.h>
using namespace std;

int N;

int solve() {
    int ans = 0;
    for (int i = 2; i < N; ++i) {
        ans += (N / i - 1) * i;
        ans %= 1'000'000;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    cout << solve();
    return 0;
}
