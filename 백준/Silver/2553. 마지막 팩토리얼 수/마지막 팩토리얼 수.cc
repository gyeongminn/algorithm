#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define endl '\n'
using namespace std;

int main(void) {
    fastio;
    int n;
    cin >> n;
    ll res = 1;
    for (int i = 1; i <= n; i++) {
        res = (res * i) % 10000000;
        while (!(res % 10)) res /= 10;
    }
    cout << res % 10 << '\n';
}
