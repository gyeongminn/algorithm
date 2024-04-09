#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll T, M;
ll N;
vector<ll> v;

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

ll pow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) {
            ret = ret * a;
            b--;
        }
        a = a * a;
        b >>= 1;
    }
    return ret;
}

ll mod_pow(ll a, ll b, ll m) {
    ll ret = 1;
    while (b) {
        if (b & 1) {
            ret = (ret * a) % m;
            b--;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return ret;
}

bool is_a_pow_b_bigger_than_100(ll a, ll b) {
    if (a > 100) return true;
    if (a == 1 || b == 1) return false;
    if (a == 2 && b > 6) return true;
    if (a == 3 && b > 4) return true;
    if (a == 4 && b > 3) return true;
    if (5 <= a && a <= 10 && b > 2) return true;
    if (a > 10) return true;
    return false;
}

ll power_tower_naive(ll cur) {
    ll ret = v[N - 1];
    for (ll i = N - 2; i >= cur; --i) {
        if (is_a_pow_b_bigger_than_100(v[i], ret)) return -1;
        ret = pow(v[i], ret);
    }

    return ret;
}

ll power_tower(ll cur, ll m) {
    if (m == 1) return 0;
    if (cur == N - 1 || v[cur + 1] == 1) return v[cur] % m;

    ll exp = power_tower_naive(cur + 1);
    if (N - cur <= 4 && exp != -1) {
        return mod_pow(v[cur], exp, m);
    }

    ll mod = phi(m);
    exp = power_tower(cur + 1, mod);
    return mod_pow(v[cur], exp + 100 * mod, m);
}

void solve() {
    cin >> N;
    v.resize(N);
    for (ll &i : v) cin >> i;
    cout << power_tower(0, M) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> T >> M;
    while (T--) solve();
    return 0;
}