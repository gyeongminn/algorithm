#include <bits/stdc++.h>
using namespace std;

typedef struct pos {
  int x, y;
} pos;

bool check[6][6];
vector<pos> v(36);

bool is_knight_move(pos a, pos b) {
    bool ret = false;
    int dy = abs(a.x - b.x);
    int dx = abs(a.y - b.y);
    if (dy == 2 && dx == 1) ret = true;
    if (dy == 1 && dx == 2) ret = true;
    return ret;
}

string solve() {
    if (!is_knight_move(v.front(), v.back())) return "Invalid";

    pos post = {-1, -1};
    for (pos &now : v) {
        bool &visit = check[now.x][now.y];
        if (visit) return "Invalid";
        else visit = true;

        if (post.x != -1 && !is_knight_move(now, post))
            return "Invalid";
        post = now;
    }

    return "Valid";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    memset(check, 0, sizeof(check));
    for (pos &p : v) {
        string s;
        cin >> s;
        p = {s[0] - 'A', s[1] - '1'};
    }

    cout << solve();
    return 0;
}