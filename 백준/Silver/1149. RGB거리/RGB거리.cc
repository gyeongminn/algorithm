#include <bits/stdc++.h>
using namespace std;

int N;
int info[1000][3];
int cache[1000][3];

int dp(int depth, int color) {
    if (depth == N) return 0;

    int &ret = cache[depth][color];
    if (ret != -1) return ret;

    ret = INT_MAX;
    for (int next_color = 0; next_color < 3; ++next_color) {
        if (color == next_color) continue;

        int current_cost = info[depth][color];
        int value = current_cost + dp(depth + 1, next_color);
        ret = min(ret, value);
    }

    return ret;
}

void solve() {
    int answer = INT_MAX;
    for (int start_color = 0; start_color < 3; ++start_color) {
        int value = dp(0, start_color);
        answer = min(answer, value);
    }
    cout << answer;
}

void initialize() {
    fill_n(&cache[0][0], 1000 * 3, -1);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> info[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    initialize();
    solve();
    return 0;
}