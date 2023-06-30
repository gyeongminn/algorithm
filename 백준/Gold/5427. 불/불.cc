#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;

typedef struct point {
    int x, y;
} point;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int w, h;

char board[1000][1000];
int fire[1000][1000];
int graph[1000][1000];
queue<point> q;

void init() {
    fill(&board[0][0], &board[999][999], 0);
    fill(&fire[0][0], &fire[999][999], 0);
    fill(&graph[0][0], &graph[999][999], 0);
    q = queue<point>();
}

bool is_finish(point p) {
    if (p.x == 0 || p.x == w - 1 || p.y == 0 || p.y == h - 1) {
        return true;
    }
    return false;
}

bool check(point p) {
    if (p.x < 0 || p.x >= w || p.y < 0 || p.y >= h) {
        return false;
    }
    if (board[p.y][p.x] == '#' || board[p.y][p.x] == '*') {
        return false;
    }
    return true;
}

void fire_bfs() {
    while (!q.empty()) {
        point cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            point next = {dx[i] + cur.x, dy[i] + cur.y};
            if (!check(next) || fire[next.y][next.x] > 0)
                continue;
            fire[next.y][next.x] = fire[cur.y][cur.x] + 1;
            q.push(next);
        }
    }
}

string bfs() {
    while (!q.empty()) {
        point cur = q.front();
        q.pop();
        if (is_finish(cur)) {
            return to_string(graph[cur.y][cur.x]);
        }
        for (int i = 0; i < 4; i++) {
            point next = {dx[i] + cur.x, dy[i] + cur.y};
            if (!check(next) || graph[next.y][next.x] > 0)
                continue;
            if (fire[next.y][next.x] != 0 && graph[cur.y][cur.x] + 1 > fire[next.y][next.x])
                continue;
            graph[next.y][next.x] = graph[cur.y][cur.x] + 1;
            q.push(next);
        }
    }
    return "IMPOSSIBLE";
}

void solve() {
    cin >> w >> h;
    point start;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> board[y][x];
            if (board[y][x] == '@') {
                start = {x, y};
                graph[y][x] = 1;
            } else if (board[y][x] == '*') {
                q.push({x, y});
            }
        }
    }
    fire_bfs();
    q = queue<point>();
    q.push(start);
    cout << bfs() << endl;
}

int main(void) {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        init();
        solve();
    }
}