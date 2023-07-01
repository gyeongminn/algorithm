#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define endl '\n'

using namespace std;

int graph[100][100];
int n, m;

void input() {
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = 1;
        graph[b - 1][a - 1] = -1;
    }
}

void get_floyd() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][k] == graph[k][j] && graph[i][k]) {
                    graph[i][j] = graph[i][k];
                }
            }
        }
    }
}

int main() {
    fastio;
    cin >> n >> m;
    input();
    get_floyd();
    for (int i = 0; i < n; ++i) {
        int cnt = -1;
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] == 0) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}