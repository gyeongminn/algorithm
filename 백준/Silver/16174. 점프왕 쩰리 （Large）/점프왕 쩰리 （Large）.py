import sys
from collections import deque
input = sys.stdin.readline


def bfs(start):
    queue = deque([start])
    x, y = start
    visited[x][y] = True
    while queue:
        x, y = queue.popleft()
        move = graph[y][x]
        for dx, dy in zip((0, move), (move, 0)):
            nx, ny = x + dx, y + dy
            if nx == n - 1 and ny == n - 1:
                return True
            if nx not in range(n) or ny not in range(n):
                continue
            if not visited[ny][nx]:
                visited[ny][nx] = True
                queue.append((nx, ny))
    return False


n = int(input())
graph = [[int(x) for x in input().split()] for _ in range(n)]
visited = [[False] * n for _ in range(n)]
print("HaruHaru" if bfs((0, 0)) else "Hing")
