import sys
from collections import deque

input = sys.stdin.readline
move = [(0, 1), (0, -1), (1, 0), (-1, 0)]


def bfs(start):
    queue = deque([start])
    x, y = start
    visited[y][x] = True
    while queue:
        x, y = queue.popleft()
        for dx, dy in move:
            nx, ny = x + dx, y + dy
            if nx not in range(m) or ny not in range(n):
                continue
            if not visited[ny][nx]:
                visited[ny][nx] = True
                queue.append((nx, ny))


t = int(input())

for _ in range(t):
    m, n, k = map(int, input().split())
    visited = [[True] * m for _ in range(n)]
    for _ in range(k):
        x, y = map(int, input().split())
        visited[y][x] = False
    count = 0
    for y in range(n):
        for x in range(m):
            if not visited[y][x]:
                count += 1
                bfs((x, y))
    print(count)
