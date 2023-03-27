#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(void) {
    fastio;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int n = a * d + b * c, m = b * d;
    int g = gcd(n, m);
    n /= g;
    m /= g;
    cout << n << ' ' << m;
}