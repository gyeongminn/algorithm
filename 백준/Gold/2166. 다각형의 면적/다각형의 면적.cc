#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define ll long long
using namespace std;

struct Point {
    ll x, y;
};

vector<Point> v;

ll getArea(Point a, Point b, Point c) {
    return (a.x * b.y + b.x * c.y + c.x * a.y) - (a.x * c.y + c.x * b.y + b.x * a.y);
}

int main(void) {
    fastio;
    int n;
    cin >> n;

    Point p;
    for (int i = 0; i < n; i++) {
        cin >> p.x >> p.y;
        v.push_back(p);
    }

    ll sum = 0;
    for (int i = 1; i < v.size() - 1; i++) {
        sum += getArea(v[0], v[i], v[i + 1]);
    }

    cout.setf(ios::fixed);
    cout.precision(1);
    cout << abs(sum) / 2.0;
}