#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

#define ull uint64_t
#define endl '\n'
using namespace std;

constexpr ull MAX = 10'000'000;
bool isPrime[MAX + 1];
vector<ull> primes = {2};
ull A, B;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> A >> B;

    for (ull i = 3; i <= (ull) sqrt(B); i += 2) {
        if (!isPrime[i]) {
            primes.push_back(i);
            for (ull j = i * i; j <= (ull) sqrt(B); j += i) {
                isPrime[j] = true;
            }
        }
    }

    ull cnt = 0;
    for (ull p: primes) {
        ull pp = p;
        while (pp <= B / p) {
            pp *= p;
            if (pp >= A && pp <= B) cnt++;
        }
    }
    cout << cnt;
    return 0;
}