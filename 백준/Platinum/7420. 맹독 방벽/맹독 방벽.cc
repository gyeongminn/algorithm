#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
long double PI = 3.14159265358979323846;

template<class T>
struct Point {
    T x, y;
    int id = -1;

    bool operator<(const Point &other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }

    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }
};

template<class T>
__int128 polygon_area2(const vector<Point<T> > &poly) {
    int n = static_cast<int>(poly.size());
    __int128 sum = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        sum += static_cast<__int128>(poly[i].x) * poly[j].y - static_cast<__int128>(poly[i].y) * poly[j].x;
    }
    if (sum < 0) sum = -sum;
    return sum;
}

template<class T>
ll boundary_lattice_points(const vector<Point<T> > &hull) {
    int n = static_cast<int>(hull.size());
    ll B = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        ll dx = llabs(static_cast<ll>(hull[i].x) - static_cast<ll>(hull[j].x));
        ll dy = llabs(static_cast<ll>(hull[i].y) - static_cast<ll>(hull[j].y));
        B += std::gcd(dx, dy);
    }
    return B;
}

template<class T>
static __int128 cross128(const Point<T> &a, const Point<T> &b, const Point<T> &c) {
    return static_cast<__int128>(b.x - a.x) * (c.y - a.y) - static_cast<__int128>(b.y - a.y) * (c.x - a.x);
}

template<class T>
bool inside_convex_ccw(const vector<Point<T> > &hull, const Point<T> &p) {
    int n = static_cast<int>(hull.size());
    if (n < 3) return false;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if (cross128(hull[i], hull[j], p) < 0) return false;
    }
    return true;
}

template<class T>
vector<Point<T> > convex_hull(vector<Point<T> > pts, bool keep_collinear = false) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());

    int n = static_cast<int>(pts.size());
    if (n <= 1) return pts;

    auto should_pop = [&](const Point<T> &a, const Point<T> &b, const Point<T> &c) -> bool {
        __int128 cr = cross128(a, b, c);
        if (keep_collinear) return cr < 0;
        return cr <= 0;
    };

    vector<Point<T> > lower, upper;
    lower.reserve(n);
    upper.reserve(n);

    for (const auto &p: pts) {
        while (static_cast<int>(lower.size()) >= 2 && should_pop(lower[static_cast<int>(lower.size()) - 2],
                                                                 lower.back(), p)) {
            lower.pop_back();
        }
        lower.push_back(p);
    }
    for (int i = n - 1; i >= 0; --i) {
        const auto &p = pts[i];
        while (static_cast<int>(upper.size()) >= 2 && should_pop(upper[static_cast<int>(upper.size()) - 2],
                                                                 upper.back(), p)) {
            upper.pop_back();
        }
        upper.push_back(p);
    }

    lower.pop_back();
    upper.pop_back();
    lower.insert(lower.end(), upper.begin(), upper.end());

    if (keep_collinear) {
        bool all_collinear = true;
        for (int i = 2; i < static_cast<int>(pts.size()); i++) {
            if (cross128(pts[0], pts[1], pts[i]) != 0) {
                all_collinear = false;
                break;
            }
        }
        if (all_collinear) {
            return pts;
        }
    }

    return lower;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll N, L;
    cin >> N >> L;
    vector<Point<ll> > v(N);
    for (auto &[x, y, id]: v) cin >> x, cin >> y;
    vector<Point<ll> > polygon = convex_hull(v);

    ld perimeter = 0;
    for (int i = 0; i < polygon.size(); i++) {
        Point<ll> cur = polygon[i], next = polygon[(i + 1) % polygon.size()];
        ll dx = cur.x - next.x, dy = cur.y - next.y;
        ld distance = sqrt(dx * dx + dy * dy);
        perimeter += distance;
    }

    ld answer = 2 * PI * L + perimeter;
    cout << round(answer);

    return 0;
}
