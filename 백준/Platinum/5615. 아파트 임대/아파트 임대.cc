#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull modPow(ull x, ull y, ull mod) {
    x %= mod;
    ull ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ull)((__int128)ret * x % mod);
        x = x * x % mod;
        y /= 2;
    }
    return ret;
}

bool isPrime(ull n) {
    if (n <= 1) return false;
    if (n < 2000000000ULL) {
        for (ull i = 2; i * i <= n; ++i)
            if (n % i == 0) return false;
        return true;
    }
    for (ull d : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        ull k = n - 1;
        while (k % 2 == 0) {
            if (modPow(d, k, n) == n - 1) return true;
            k /= 2;
        }
        ull tmp = modPow(d, k, n);
        if (k & 1) return (tmp == 1 || tmp == n - 1);
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ull N;
    cin >> N;
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        ull num;
        cin >> num;
        if (isPrime(num * 2 + 1)) cnt++;
    }
    cout << cnt;
    return 0;
}