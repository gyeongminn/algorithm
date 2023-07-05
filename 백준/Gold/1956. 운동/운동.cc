#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define endl '\n'
using namespace std;

int main(void) {
    fastio;
    int V, E;
    int graph[400][400];
    int inf = INT_MAX;
    cin >> V >> E;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = inf;
        }
        // graph[i][i] = 0;
    }
    for (int i = 0; i < E; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a - 1][b - 1] = w;
    }
    int ans = inf;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            for (int k = 0; k < V; k++) {
                if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    if (graph[i][k] == inf || graph[k][j] == inf)
                        continue;
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    for (int i = 0; i < V; i++) {
        ans = min(ans, graph[i][i]);
    }
    if (ans == inf)
        cout << -1;
    else
        cout << ans;
}