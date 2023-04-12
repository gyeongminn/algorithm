#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ull unsigned long long
#define endl '\n'
using namespace std;

ull gcd(ull a, ull b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main(void) {
    fastio;
    ull a, b;
    cin >> a >> b;
    ull res = gcd(a, b);
    while (res--) {
        cout << '1';
    }
}
