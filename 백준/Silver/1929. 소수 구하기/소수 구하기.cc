#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

#define ll long long
#define endl '\n'
using namespace std;

int LO, HI;

bool isPrime(int n) {
    if (n == 2) return true;
    if (n <= 1 || !(n & 1)) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> LO >> HI;
    for (int n = LO; n <= HI; n++) {
        if (isPrime(n)) cout << n << endl;
    }
    return 0;
}