#include <bits/stdc++.h>
using namespace std;

typedef struct point {
  int r, c;
} point;

// 상하반전
int dir;
point dirs[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool visited[1000][1000];
int cnt;
int C, R, K;

void dfs(point p) {
//    cout << p.r + 1 << ' ' << p.c + 1 << endl;
    visited[p.r][p.c] = true;
    if (++cnt == K) {
        cout << p.c + 1 << ' ' << p.r + 1 << endl;
        return;
    }
    point next = {p.r + dirs[dir].r, p.c + dirs[dir].c};
    if (next.r >= R || next.r < 0 || next.c >= C || next.c < 0 || visited[next.r][next.c]) {
        dir = (dir + 1) % 4;
        point next_ = {p.r + dirs[dir].r, p.c + dirs[dir].c};
        dfs(next_);
    } else {
        if (!visited[next.r][next.c]) {
            dfs(next);
        }
    }
}

void solve() {
    if (C * R < K) {
        cout << 0;
    } else {
        dfs({0, 0});
    }
}

void input() {
    cin >> C >> R >> K;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}