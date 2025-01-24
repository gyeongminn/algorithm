#include <bits/stdc++.h>
using namespace std;

int N, M;
int graph[101][101];
const int inf = INT_MAX / 2;

void solve() {
    pair<int, int> answer;
    int minDistance = INT_MAX;
    for (int first = 1; first <= N; ++first) {
        for (int second = first + 1; second <= N; ++second) {
            int sumDistance = 0;
            for (int i = 1; i <= N; ++i) {
                sumDistance += min(graph[first][i], graph[second][i]);
            }

            if (sumDistance < minDistance) {
                answer = {first, second};
                minDistance = sumDistance;
            }
        }
    }

    cout << answer.first << ' ' << answer.second << ' ' << minDistance * 2;
}

void applyFloydWarshall() {
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
}

void initialize() {
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= 100; ++j) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = inf;
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    initialize();
    input();
    applyFloydWarshall();
    solve();
    return 0;
}