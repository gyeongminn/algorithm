#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, M;

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

ll db[5] = {1, 1, 2, 9, 262144};

ll power_tower(ll cur, ll m) {
    if (m == 1) return 1;

    if (cur < 5) {
        return db[cur] % m;
    } else if (cur == 5) {
        return mod_pow(cur, db[4], m);
    }

    ll mod = phi(m);
    ll exp = power_tower(cur - 1, mod);
    return mod_pow(cur, exp + mod, m);
}

ll solve() {
    cin >> N >> M;
    if (M == 1) return 0;
    return power_tower(N, M);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}