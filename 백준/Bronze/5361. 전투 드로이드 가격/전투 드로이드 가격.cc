#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    printf("$%.2f\n", a * 350.34 + b * 230.90 + c * 190.55 + d * 125.30 + e * 180.90);
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}