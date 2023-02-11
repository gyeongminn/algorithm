import sys
from collections import deque

input = sys.stdin.readline
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]


def bfs():
    queue = deque()
    for y in range(n):
        for x in range(m):
            if graph[y][x] == 1:
                queue.append((x, y))
                
    while queue:
        x, y = queue.popleft()
        for _dx, _dy in zip(dx, dy):
            nx, ny = x + _dx, y + _dy
            if nx not in range(m) or ny not in range(n):
                continue
            if graph[ny][nx] == 0:
                graph[ny][nx] = graph[y][x] + 1
                queue.append((nx, ny))

    result = 0
    for y in range(n):
        for x in range(m):
            if graph[y][x] == 0:
                return -1
            result = max(result, graph[y][x])
    return result - 1


m, n = map(int, input().split())
graph = [[int(x) for x in input().split()] for _ in range(n)]

print(bfs())
