#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Euler Phi
ll phi(ll n) {
    ll s = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            s = s / i * (i - 1);
        }
    }
    if (n > 1) s = s / n * (n - 1);
    return s;
}

// Calc n ^ k mod m
ll fast_exp(ll n, ll k, ll m) {
    ll ret = 1;
    while (k) {
        if (k & 1) {
            ret = (ret * n) % m;
            k--;
        }
        n = (n * n) % m;
        k >>= 1;
    }
    return ret;
}

// Calc power_tower(n, k) <= 100 ?
bool is_smaller_than_100(ll n, ll k) {
    ll a = 1;
    for (int i = 0; i < k; ++i) {
        a *= n;
        if (a > 100) return false;
    }
    return true;
}

// Calc n^n^n^n^... mod m (k times)
ll power_tower(ll n, ll k, ll m) {
    if (m == 1) return 0;
    if (k <= 4 && is_smaller_than_100(n, k)) {
        ll exp = fast_exp(n, k - 1, m);
        return fast_exp(n, exp, m);
    } else {
        ll mod = phi(m);
        ll exp = power_tower(n, k - 1, mod);
        return fast_exp(n, exp + 100 * mod, m);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    cout << power_tower(n, LLONG_MAX, m) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}