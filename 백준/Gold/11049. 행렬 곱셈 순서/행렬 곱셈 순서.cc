#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> matrix[500];
int cache[500][500];

int solve(int left, int right) {
    if (left == right) return 0;

    int &ret = cache[left][right];
    if (ret != -1) return ret;

    ret = INT_MAX;
    for (int mid = left; mid < right; ++mid) {
        int left_cost = solve(left, mid);
        int right_cost = solve(mid + 1, right);
        int mid_cost = matrix[left].first * matrix[mid].second * matrix[right].second;

        int cost = left_cost + mid_cost + right_cost;
        ret = min(ret, cost);
    }

    return ret;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> matrix[i].first >> matrix[i].second;
    }

    memset(cache, -1, sizeof(cache));
    cout << solve(0, N - 1);
}
