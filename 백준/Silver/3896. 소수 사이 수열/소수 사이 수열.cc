#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<int> sieve(int n) {
    vector<int> primes;
    vector<bool> state(n + 1, true);
    state[0] = state[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (!state[i])
            continue;
        for (int j = i * i; j <= n; j += i) {
            state[j] = false;
        }
    }
    for (int i = 0; i <= n; i++) {
        if (state[i])
            primes.push_back(i);
    }
    return primes;
}

int isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
    fastio;
    vector<int> primes = sieve(1299709);
    int t, k;
    cin >> t;
    while (t--) {
        cin >> k;
        if (k == 1 || isPrime(k)) {
            cout << 0 << '\n';
            continue;
        }
        int idx = upper_bound(primes.begin(), primes.end(), k) - primes.begin();
        cout << primes[idx] - primes[idx - 1] << '\n';
    }
}