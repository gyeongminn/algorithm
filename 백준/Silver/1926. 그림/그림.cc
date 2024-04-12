#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[501][501];

bool visited[501][501];
int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

int bfs(int r, int c) {
    queue<pair<int, int>> q;

    visited[r][c] = true;
    q.emplace(r, c);

    int area = 0;
    while (!q.empty()) {
        area++;
        
        pair<int, int> next = q.front();
        r = next.first, c = next.second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (visited[nr][nc] || A[nr][nc] != 1) continue;
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

            visited[nr][nc] = true;
            q.emplace(nr, nc);
        }
    }

    return area;
}

void solve() {
    int max_area = 0;
    int cnt = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (A[r][c] == 1 && !visited[r][c]) {
                int area = bfs(r, c);
                max_area = max(max_area, area);
                cnt++;
            }
        }
    }
    cout << cnt << '\n' << max_area;
}

void input() {
    cin >> N >> M;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
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