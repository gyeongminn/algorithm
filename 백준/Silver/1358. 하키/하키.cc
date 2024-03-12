#include <bits/stdc++.h>
using namespace std;

int W, H, X, Y, P;

int dist_square(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int solve() {
    int x, y;
    cin >> x >> y;

    if ((X <= x && x <= X + W) && (Y <= y && y <= Y + H)) {
        return 1;
    }

    int R = H / 2;
    if (dist_square(X, Y + R, x, y) <= R * R) {
        return 1;
    }

    if (dist_square(X + W, Y + R, x, y) <= R * R) {
        return 1;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> W >> H >> X >> Y >> P;

    int ans = 0;
    for (int i = 0; i < P; ++i) {
        ans += solve();
    }
    cout << ans;
    return 0;
}