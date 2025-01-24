#include <bits/stdc++.h>
using namespace std;

struct point { int x, y; };

int N;
vector<point> points;

int compareWithX(point a, point b) { return a.x > b.x; }
int compareWithY(point a, point b) { return a.y > b.y; }
int square(int n) { return n * n; }
int dist_square(point a, point b) { return square(a.x - b.x) + square(a.y - b.y); }

int processMidPart(int left, int right, int mid, int searchDistance) {
    point midPoint = points[mid];
    vector<point> candidates;
    for (int i = left; i <= right; ++i) {
        if (square(points[i].x - midPoint.x) < searchDistance) {
            candidates.push_back(points[i]);
        }
    }

    sort(candidates.begin(), candidates.end(), compareWithY);

    for (int i = 0; i < candidates.size(); i++) {
        for (int j = i - 1; j >= 0; --j) {
            if (square(candidates[i].y - candidates[j].y) < searchDistance) {
                searchDistance = min(searchDistance, dist_square(candidates[i], candidates[j]));
            } else {
                break;
            }
        }
    }

    return searchDistance;
}

int solve(int left, int right) {
    if (left == right) return INT_MAX;

    int mid = (left + right) / 2;

    int leftPart = solve(left, mid);
    int rightPart = solve(mid + 1, right);

    int minDistance = min(leftPart, rightPart);
    minDistance = processMidPart(left, right, mid, minDistance);

    return minDistance;
}

void input() {
    cin >> N;
    points.resize(N);
    for (auto &[x, y] : points) cin >> x >> y;
    sort(points.begin(), points.end(), compareWithX);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    cout << solve(0, N - 1);
    return 0;
}