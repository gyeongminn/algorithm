import sys

input = sys.stdin.readline
inf = float('inf')
n, m = map(int, input().split())
dist, graph = [[inf]*n for _ in range(n)], []

for _ in range(m):
    a, b, w = map(int, input().split())
    a, b = a - 1, b - 1
    dist[a][b] = min(w, dist[a][b])
    dist[b][a] = min(w, dist[b][a])
    graph.append((a, b, w))

for i in range(n):
    dist[i][i] = 0

for k in range(n):
    for i in range(n):
        for j in range(n):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

res = inf
for s in range(n):
    val = 0
    for a, b, w in graph:
        val = max(val, dist[s][a] + dist[s][b] + w)
    res = min(res, val)
print(res / 2)
