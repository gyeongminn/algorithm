#include <bits/stdc++.h>
using namespace std;

struct point {
  int r, c;
};

int R, C;
int A[301][301];
bool visited[301][301];
point moves[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(point start) {
    queue<point> q;
    q.push(start);
    visited[start.r][start.c] = true;

    while (!q.empty()) {
        point cur = q.front();
        q.pop();

        for (point move : moves) {
            point next = {cur.r + move.r, cur.c + move.c};
            if (next.r < 0 || next.r >= R || next.c < 0 || next.c >= C) continue;
            if (visited[next.r][next.c] || A[next.r][next.c] <= 0) continue;

            visited[next.r][next.c] = true;
            q.push(next);
        }
    }
}

void melting() {
    // 얼만큼 녹일건지 계산
    int diff[301][301];
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            int near_zero_cnt = 0;
            for (point move : moves) {
                point next = {r + move.r, c + move.c};
                if (next.r < 0 || next.r >= R || next.c < 0 || next.c >= C) continue;
                if (A[next.r][next.c] == 0) near_zero_cnt++;
            }
            diff[r][c] = near_zero_cnt;
        }
    }

    // 녹이기
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            A[r][c] -= diff[r][c];
            if (A[r][c] < 0) A[r][c] = 0;
        }
    }
}

int solve() {
    for (int i = 0; i <= 1e9; ++i) {
        memset(visited, false, sizeof(visited));

        bool is_all_zero = true;
        int cnt = 0; // BFS가 몇 번 호출되는지 카운트
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (A[r][c] > 0) is_all_zero = false;

                // 방문한 적이 없거나, 녹지 않으면 탐색
                if (A[r][c] > 0 && !visited[r][c]) {
                    bfs({r, c});
                    cnt++;
                }
            }
        }

        if (is_all_zero) return 0;
        if (cnt >= 2) return i;

        // 인접한 0의 개수만큼 빙하를 녹인다
        melting();
    }
    return -1;
}

void input() {
    cin >> R >> C;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> A[r][c];
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    cout << solve();
    return 0;
}