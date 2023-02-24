#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define ll long long
using namespace std;

struct Point {
    ll x, y;
};

ll ccw(const Point &a, const Point &b, const Point &c) {
    return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (c.x - a.x) * (b.y - a.y);
}

int main(void) {
    fastio;
    Point a, b, c;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    ll result = ccw(a, b, c);
    if (result > 0) {
        cout << 1;
    } else if (result < 0) {
        cout << -1;
    } else {
        cout << 0;
    }
}