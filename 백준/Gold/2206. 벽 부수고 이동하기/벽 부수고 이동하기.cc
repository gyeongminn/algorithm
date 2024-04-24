#include <bits/stdc++.h>
using namespace std;

struct point {
  int r, c, step, cnt;
};

int R, C;
char board[1000][1000];
bool visited[1000][1000][2];
point moves[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(point start) {
    queue<point> q;

    // 탐색 시작 위치
    visited[start.r][start.c][0] = true;
    q.push(start);

    while (!q.empty()) {
        point cur = q.front();
        q.pop();

        // 종료 조건
        if (cur.r == R - 1 && cur.c == C - 1) return cur.step;

        for (point move : moves) {
            point next = {cur.r + move.r, cur.c + move.c, cur.step + 1, cur.cnt};

            // 범위 및 방문 여부 체크
            if (next.r < 0 || next.r >= R || next.c < 0 || next.c >= C) continue;
            if (visited[next.r][next.c][next.cnt]) continue;

            // 벽 없는 경우
            if (board[next.r][next.c] == '0') {
                visited[next.r][next.c][next.cnt] = true;
                q.push(next);
            }

            // 벽인데 뚫을 수 있는 경우
            if (board[next.r][next.c] == '1' && next.cnt == 0) {
                visited[next.r][next.c][1] = true;
                q.push({next.r, next.c, next.step, next.cnt + 1});
            }
        }
    }

    // 못 찾은 경우
    return -1;
}

void solve() {
    cout << bfs({0, 0, 1, 0});
}

void input() {
    cin >> R >> C;
    for (int r = 0; r < R; ++r) {
        string s;
        cin >> s;
        for (int c = 0; c < C; ++c) {
            board[r][c] = s[c];
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}