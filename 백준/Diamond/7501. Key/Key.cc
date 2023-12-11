#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull modPow(ull x, ull y, ull mod) {
    x %= mod;
    ull ret = 1;
    while (y > 0) {
        if (y & 1) ret = (__int128)ret * x % mod;
        x = (__int128)x * x % mod;
        y /= 2;
    }
    return ret;
}

bool sqrtPrimeTest(ull n) {
    for (ull i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

bool millerRabin(ull n, ull d) {
    ull k = n - 1;
    while (k % 2 == 0) {
        if (modPow(d, k, n) == n - 1) return true;
        k /= 2;
    }
    ull tmp = modPow(d, k, n);
    return (tmp == 1 || tmp == n - 1);
}

bool isPrime(ull n) {
    if (n <= 1) return false;
    if (n < 2000000000) return sqrtPrimeTest(n);
    for (ull d : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (n % d == 0) return false;
        if (!millerRabin(n, d)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ull a, b;
    cin >> a >> b;
    for (ull k = a; k <= b; ++k) {
        if (k == 9 || isPrime(k)) {
            cout << k << ' ';
        }
    }
    return 0;
}