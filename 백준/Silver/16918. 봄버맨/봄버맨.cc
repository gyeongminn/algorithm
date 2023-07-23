#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define endl '\n'
using namespace std;

int R, C, N;
char graph[202][202];
bool visited[202][202];
int dr[5] = {0, 0, -1, 1, 0};
int dc[5] = {-1, 1, 0, 0, 0};

void bomb() {
    fill(&visited[0][0], &visited[200][200], false);
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            int nr, nc;
            if (graph[r][c] == 'O') {
                for (int i = 0; i < 5; ++i) {
                    nr = r + dr[i];
                    nc = c + dc[i];
                    if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                    visited[nr][nc] = true;
                }
            }
        }
    }
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            graph[r][c] = (visited[r][c]) ? '.' : 'O';
        }
    }
}

void solve() {
    if (N == 1) {
        // 1이면 아무 일도 없다
        return;
    } else if (!(N & 1)) {
        // 짝수면 전부 폭탄
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                graph[r][c] = 'O';
            }
        }
    } else if (N % 4 == 3) {
        // 3 7 11 (4로 나눈 나머지가 3) -> 한 번 폭탄
        bomb();
    } else {
        // 5 9 13 (4로 나눈 나머지가 1) -> 두 번 폭탄
        bomb();
        bomb();
    }
}


int main() {
    fastio;
    cin >> R >> C >> N;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> graph[r][c];
        }
    }
    solve();
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cout << graph[r][c];
        }
        cout << endl;
    }
    return 0;
}