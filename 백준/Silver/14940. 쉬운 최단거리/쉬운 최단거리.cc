#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[1000][1000];

int start_r, start_c;
int B[1000][1000];
vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void bfs(int r, int c, int cnt) {
    queue<tuple<int, int, int>> q;
    q.emplace(r, c, cnt);

    while (!q.empty()) {
        auto [now_r, now_c, now_cnt] = q.front();
        q.pop();

        int next_cnt = now_cnt + 1;
        for (auto [dr, dc] : dirs) {
            int next_r = now_r + dr;
            int next_c = now_c + dc;
            if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M) continue;
            if (B[next_r][next_c] > 0 || A[next_r][next_c] != 1) continue;

            B[next_r][next_c] = next_cnt;
            q.emplace(next_r, next_c, next_cnt);
        }
    }
}

void solve() {
    bfs(start_r, start_c, 0);

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (start_r == r && start_c == c) cout << 0 << ' ';
            else if (A[r][c] == 1 && B[r][c] == 0) cout << -1 << ' ';
            else cout << B[r][c] << ' ';
        }
        cout << '\n';
    }
}

void input() {
    cin >> N >> M;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            cin >> A[r][c];
            if (A[r][c] == 2) {
                start_r = r;
                start_c = c;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}