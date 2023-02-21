import sys
from collections import deque

input = sys.stdin.readline
move = [(-2, 1), (-1, 2), (1, 2), (2, 1), (-2, -1), (-1, -2), (1, -2), (2, -1)]


def bfs(start):
    queue = deque([start])
    x, y = start
    graph[y][x] = 0
    while queue:
        x, y = queue.popleft()
        if (x, y) == end:
            return graph[y][x]
        for dx, dy in move:
            nx, ny = x + dx, y + dy
            if nx not in range(size) or ny not in range(size):
                continue
            if graph[ny][nx] == 0:
                graph[ny][nx] = graph[y][x] + 1
                queue.append((nx, ny))


t = int(input())
for _ in range(t):
    size = int(input())
    graph = [[False] * size for _ in range(size)]
    start = tuple(map(int, input().split()))
    end = tuple(map(int, input().split()))
    print(bfs(start))
