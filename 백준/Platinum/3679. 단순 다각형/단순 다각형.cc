#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define ll long long
#define endl '\n'
using namespace std;

struct Point {
    ll x, y, idx;
};

Point arr[100000];
stack<Point> s;

ll ccw(const Point &a, const Point &b, const Point &c) {
    return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (c.x - a.x) * (b.y - a.y);
}

bool compare_y(const Point &a, const Point &b) {
    if (a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

bool compare_ccw(const Point &a, const Point &b) {
    ll c = ccw(arr[0], a, b);
    if (c == 0)
        return compare_y(a, b);
    return c > 0;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
        arr[i].idx = i;
    }

    sort(arr, arr + n, compare_y);
    sort(arr + 1, arr + n, compare_ccw);

    int pt = n - 1;
    for (int i = n - 1; i >= 1; i--) {
        if (ccw(arr[0], arr[pt], arr[pt - 1]) == 0) {
            pt--;
        } else {
            break;
        }
    }
    reverse(arr + pt, arr + n);

    for (int i = 0; i < n; i++) {
        cout << arr[i].idx << ' ';
    }
    cout << endl;
}

int main(void) {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}