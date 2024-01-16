#include <bits/stdc++.h>
using namespace std;

int N, R, C;
int cnt;

void solve(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) return;
    if (x2 >= (1 << N) || y2 >= (1 << N)) return;
    if (x2 - x1 != y2 - y1) return;

    if (x1 == x2 && y1 == y2) {
        if (x1 == C && y1 == R) {
            cout << cnt << endl;
        } else {
            cnt++;
        }
        return;
    }

    int mid_x = (x1 + x2) / 2;
    int mid_y = (y1 + y2) / 2;

    if (C >= x1 && C <= x2 && R >= y1 && R <= y2) {
        solve(x1, y1, mid_x, mid_y); // 왼쪽 위
        solve(mid_x + 1, y1, x2, mid_y); // 오른쪽 위
        solve(x1, mid_y + 1, mid_x, y2); // 왼쪽 아래
        solve(mid_x + 1, mid_y + 1, x2, y2); // 오른쪽 아래
    } else {
        cnt += (y2 - y1 + 1) * (x2 - x1 + 1);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> R >> C;
    solve(0, 0, (1 << N) - 1, (1 << N) - 1);
    return 0;
}