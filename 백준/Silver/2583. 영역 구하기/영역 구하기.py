import sys
from collections import deque

input = sys.stdin.readline


def bfs(start, region):
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    q = deque([start])
    while q:
        x, y = q.popleft()
        graph[y][x] = region
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < m and graph[ny][nx] == 0:
                graph[ny][nx] = region
                q.append((nx, ny))


m, n, k = map(int, input().split())
graph = [[0] * n for _ in range(m)]

for _ in range(k):
    x1, y1, x2, y2 = map(int, input().split())
    for y in range(y1, y2):
        for x in range(x1, x2):
            graph[y][x] = -1

region = 0
for y in range(m):
    for x in range(n):
        if graph[y][x] == 0:
            region += 1
            bfs((x, y), region)

result = []
for i in range(1, region+1):
    num = 0
    for row in graph:
        num += row.count(i)
    result.append(num)

print(len(result))
print(*sorted(result))
