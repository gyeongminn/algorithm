import sys

input = sys.stdin.readline
inf = sys.maxsize

n, m = map(int, input().split())
graph = [[inf]*n for _ in range(n)]
result = (0, inf)

for _ in range(m):
    x, y = map(int, input().split())
    graph[x-1][y-1] = 1
    graph[y-1][x-1] = 1

for k in range(n):
    for i in range(n):
        for j in range(n):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

for i in range(n):
    count = 0
    for j in range(n):
        if i == j:
            continue
        count += graph[i][j]
    if count < result[1]:
        result = (i, count)

print(result[0] + 1)
