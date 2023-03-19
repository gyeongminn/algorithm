#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
using namespace std;

set<ll> reset = {0};
ll prefix[200001];

int main(void) {
    fastio;
    ll n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i - 1];
    }

    while (q--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            ll d;
            cin >> d;
            reset.insert(d);
        } else {
            ll s, e;
            cin >> s >> e;
            cout << prefix[e] - prefix[max(s - 1, *(--reset.lower_bound(e)))] << endl;
        }
    }
}