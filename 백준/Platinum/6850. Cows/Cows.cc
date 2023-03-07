#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define ll long long
using namespace std;

struct Point {
    ll x, y;
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

ll getArea(Point a, Point b, Point c) {
    return abs((a.x * b.y + b.x * c.y + c.x * a.y) - (a.x * c.y + c.x * b.y + b.x * a.y));
}

int main(void) {
    fastio;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }

    sort(arr, arr + n, compare_y);
    sort(arr + 1, arr + n, compare_ccw);

    s.push(arr[0]);
    s.push(arr[1]);

    Point first, second;
    for (int i = 2; i < n; i++) {
        while (s.size() > 1) {
            second = s.top();
            s.pop();
            first = s.top();
            if (ccw(first, second, arr[i]) > 0) {
                s.push(second);
                break;
            }
        }
        s.push(arr[i]);
    }
    
    vector<Point> v;
    
    while (s.size() > 0) {
        v.push_back(s.top());
        s.pop();
    }

    sort(v.begin(), v.end(), compare_y);
    sort(v.begin(), v.end(), compare_ccw);

    ll sum = 0;
    for (int i = 1; i < v.size() - 1; i++) {
        sum += getArea(v[0], v[i], v[i+1]);
    }
    cout << sum / 2 / 50;
}