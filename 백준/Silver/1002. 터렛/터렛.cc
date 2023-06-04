#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define endl '\n'
using namespace std;

typedef struct Point {
    int x, y;
} Point;

ll dist_seq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

ll solve() {
    Point p1, p2;
    int r1, r2;
    cin >> p1.x >> p1.y >> r1 >> p2.x >> p2.y >> r2;
    if (p1.x == p2.x && p1.y == p2.y && r1 == r2) {
        return -1;
    }
    ll seq_d = dist_seq(p1, p2);
    if ((r1 - r2) * (r1 - r2) < seq_d && seq_d < (r1 + r2) * (r1 + r2)) {
        return 2;
    }
    if (seq_d == (r1 + r2) * (r1 + r2) || seq_d == (r1 - r2) * (r1 - r2)) {
        return 1;
    }
    return 0;
}

int main(void) {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
}