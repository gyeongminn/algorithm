#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;

typedef struct point {
    int r, c;
} point;

int n, k;
int graph[50][50];
bool visited[50][50];
int inf = numeric_limits<int>::max();

void input() {
    cin >> n >> k;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> graph[r][c];
        }
    }
}

bool check_start_end() {
    if (graph[0][0] == 1 || graph[0][0] == 5) {
        if (graph[n - 1][n - 1] == 2 || graph[n - 1][n - 1] == 5) {
            return true;
        }
    }
    return false;
}

pair<point, point> get_link(point p) {
    switch (graph[p.r][p.c]) {
        case 0:
            return {{p.r + 1, p.c},
                    {p.r,     p.c + 1}};
        case 1:
            return {{p.r,     p.c - 1},
                    {p.r + 1, p.c}};
        case 2:
            return {{p.r - 1, p.c},
                    {p.r,     p.c + 1}};
        case 3:
            return {{p.r,     p.c - 1},
                    {p.r - 1, p.c}};
        case 4:
            return {{p.r + 1, p.c},
                    {p.r - 1, p.c}};
        case 5:
            return {{p.r, p.c + 1},
                    {p.r, p.c - 1}};
    }
    return {p, p};
}

bool check(point p) {
    if (p.r < 0 || p.r >= n || p.c < 0 || p.c >= n) return false;
    if (visited[p.r][p.c]) return false;
    return true;
}

int bfs(point start) {
    fill(&visited[0][0], &visited[49][49], false);

    visited[start.r][start.c] = true;
    queue<point> q;
    q.push(start);

    int cnt = 1;
    while (!q.empty()) {
        point cur = q.front();
        q.pop();
        pair<point, point> x = get_link(cur);
        point p1 = x.first;
        point p2 = x.second;
        point next;
        if (check(p1)) {
            next = p1;
        } else if (check(p2)) {
            next = p2;
        } else {
            continue;
        }
        visited[next.r][next.c] = true;
        q.push(next);
        cnt++;
    }
    if (visited[n - 1][n - 1]) return cnt;
    else return inf;
}

void solve() {
    int dist = inf;
    if (k == 0) {
        if (check_start_end()) {
            dist = min(dist, bfs({0, 0}));
        }
    } else if (k == 1) {
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                int post = graph[r][c];
                for (int item = 0; item < 6; ++item) {
                    if (post == item) continue;
                    graph[r][c] = item;
                    if (check_start_end()) {
                        dist = min(dist, bfs({0, 0}));
                    }
                    graph[r][c] = post;
                }
            }
        }
    }
    cout << (dist == inf ? -1 : dist);
}

int main() {
    fastio;
    input();
    solve();
    return 0;
}