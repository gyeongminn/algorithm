#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;

typedef struct point {
    int r, c;
}point;

int N;
constexpr int MAX = 200;
char graph[MAX][MAX];
bool visited[MAX][MAX];
point dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(point start) {
    visited[start.r][start.c] = true;
    queue<point> q; q.push(start);
    while (!q.empty()) {
        point cur = q.front();
        q.pop();
        for (point dir : dirs) {
            point next = {cur.r + dir.r, cur.c + dir.c};
            if (next.r < 0 || next.r >= N || next.c < 0 || next.c >= N) continue;
            if (visited[next.r][next.c]) continue;
            if (graph[next.r][next.c] != graph[cur.r][cur.c]) continue;
            visited[next.r][next.c] = true;
            q.push(next);
        }
    }
}

void solve() {
    int a = 0, b = 0;
    fill(&visited[0][0], &visited[N][N], false);
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (!visited[r][c]) {
                bfs({r, c});
                a++;
            }
        }
    }

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (graph[r][c] == 'G') graph[r][c] = 'R';
        }
    }

    fill(&visited[0][0], &visited[N][N], false);
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (!visited[r][c]) {
                bfs({r, c});
                b++;
            }
        }
    }
    cout << a << ' ' << b << endl;
}

int main() {
    fastio;
    cin >> N;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cin >> graph[r][c];
        }
    }
    solve();
    return 0;
}
