#include <bits/stdc++.h>
using namespace std;

struct point {
  int r, c;
};

int N;
int A[100][100]; // 원본 배열
int B[100][100]; // 탐색할 배열
point moves[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(point start) {
    queue<point> q;
    q.push(start);

    while (!q.empty()) {
        point cur = q.front();
        q.pop();

        for (point move : moves) {
            point next = {cur.r + move.r, cur.c + move.c};
            if (next.r < 0 || next.r >= N || next.c < 0 || next.c >= N) continue;
            if (B[next.r][next.c] <= 0) continue;

            B[next.r][next.c] = 0;
            q.push(next);
        }
    }
}

void solve() {
    int ans = 0;
    for (int i = 0; i <= 100; ++i) {
        // 값 복사하고 침수된 부분은 0으로 처리
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                B[r][c] = A[r][c];
                if (B[r][c] <= i) B[r][c] = 0;
            }
        }

        // 몇 번 BFS가 호출되는지 카운트
        int cnt = 0;
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                // 방문한 적이 없거나, 침수가 되지 않은 경우
                if (B[r][c] > 0) {
                    bfs({r, c});
                    cnt++;
                }
            }
        }

        // 최대 카운트가 정답
        ans = max(ans, cnt);
    }

    cout << ans;
}

void input() {
    cin >> N;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cin >> A[r][c];
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}