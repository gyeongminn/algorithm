#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define endl '\n'
using namespace std;

typedef struct point {
    int r, c;
} point;

point dxy[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int N, M;
int graph[10][10];
bool visited[10][10];
vector<point> virus;
int ans;

int bfs() {
    fill(&visited[0][0], &visited[9][9], false);
    queue<point> q;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (graph[r][c] == 2) {
                q.push({r, c});
            }
        }
    }
    while (!q.empty()) {
        point p = q.front();
        q.pop();
        for (point d : dxy) {
            point next = {p.r + d.r, p.c + d.c};
            if (next.r < 0 || next.r >= N || next.c < 0 || next.c >= M) {
                continue;
            }
            if (!visited[next.r][next.c] && graph[next.r][next.c] == 0) {
                visited[next.r][next.c] = true;
                q.push(next);
            }
        }
    }
    int ret = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (graph[r][c] == 0 && !visited[r][c]) {
                ret++;
            }
        }
    }
    return ret;
}

void solve(int depth) {
    if (depth == 3) {
        ans = max(ans, bfs());
        return; 
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (graph[r][c] == 0) {
                graph[r][c] = 1;
                solve(depth + 1);
                graph[r][c] = 0;
            }
        }
    }
}

int main(void) {
    fastio;
    cin >> N >> M;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> graph[r][c];
            if (graph[r][c] == 2) {
                virus.push_back({r, c});
            }
        }
    }
    solve(0);
    cout << ans << endl;
}