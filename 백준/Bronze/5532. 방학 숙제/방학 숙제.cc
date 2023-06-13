#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(void) {
    fastio;
    int l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;
    a = ceil((double)a / c);
    b = ceil((double)b / d);
    if (a < b) {
        swap(a, b);
    }
    cout << l - a;
}