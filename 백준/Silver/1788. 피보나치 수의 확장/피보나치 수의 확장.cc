#include <bits/stdc++.h>
using namespace std;

const int mod = 1'000'000'000;

int fib[2'000'100];

void solve() {
    int n;
    cin >> n;
    if (fib[n + 1'000'000] < 0) {
        cout << "-1\n";
    } else if (fib[n + 1'000'000] > 0) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }
    cout << abs(fib[n + 1'000'000]);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    fib[1'000'000 + 1] = 1;
    fib[1'000'000 - 1] = 1;
    for (int i = 2; i <= 1'000'000; ++i) {
        int k = i + 1'000'000;
        fib[k] = fib[k - 1] + fib[k - 2];
        fib[k] %= mod;
    }
    for (int i = 2; i <= 1'000'000; ++i) {
        int k = -i + 1'000'000;
        fib[k] = -fib[k + 1] + fib[k + 2];
        fib[k] %= mod;
    }
    solve();
    return 0;
}