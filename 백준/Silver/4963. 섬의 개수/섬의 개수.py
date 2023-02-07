import sys
from collections import deque

input = sys.stdin.readline

dx = [1, 0, -1, 0, -1, 1, 1, -1]
dy = [0, 1, 0, -1, -1, 1, -1, 1]


def bfs(x, y):
    queue = deque([(x, y)])
    visited[y][x] = True
    while queue:
        x, y = queue.popleft()
        for _dx, _dy in zip(dx, dy):
            nx, ny = x + _dx, y + _dy
            if nx not in range(w) or ny not in range(h):
                continue
            if visited[ny][nx] or graph[ny][nx] == 0:
                continue
            queue.append((nx, ny))
            visited[ny][nx] = True


while True:
    w, h = map(int, input().split())
    if w == h == 0:
        break
    graph = [[int(x) for x in input().split()] for _ in range(h)]
    if w == h == 1:
        print(graph[0][0])
        continue
    visited = [[False] * w for _ in range(h)]
    count = 0
    for y in range(h):
        for x in range(w):
            if graph[y][x] == 1 and not visited[y][x]:
                bfs(x, y)
                count += 1
    
    print(count)
