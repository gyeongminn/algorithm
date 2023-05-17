#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
using namespace std;

int main(void) {
    fastio;
    int d[63] = {0};
    ll n, k;
    cin >> n;
    while (n--) {
        cin >> k;
        if (k) {
            d[(int)log2(k)]++;
        }
    }
    for (int i = 0; i < 62; i++) {
        d[i + 1] += d[i] / 2;
    }
    for (int i = 62; i >= 0; i--) {
        if (d[i]) {
            cout << (ll)pow(2, i);
            return 0;
        }
    }
}