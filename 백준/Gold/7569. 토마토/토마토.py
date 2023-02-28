import sys
from collections import deque

input = sys.stdin.readline
dx = [0, 0, 1, -1, 0, 0]
dy = [1, -1, 0, 0, 0, 0]
dz = [0, 0, 0, 0, -1, 1]


def bfs():
    queue = deque()
    flag_zero = True
    flag_none = True
    for z in range(h):
        for y in range(n):
            for x in range(m):
                if graph[z][y][x] == 0:
                    flag_zero = False
                if graph[z][y][x] != -1:
                    flag_none = False
                if graph[z][y][x] == 1:
                    queue.append((x, y, z))
    if flag_none:
        return -1
    
    while queue:
        x, y, z = queue.popleft()
        for _dx, _dy, _dz in zip(dx, dy, dz):
            nx, ny, nz = x + _dx, y + _dy, z + _dz
            if nx not in range(m) or ny not in range(n) or nz not in range(h):
                continue
            if z == 0 and y == 1 and x == 2:
                pass
            if graph[nz][ny][nx] == 0:
                graph[nz][ny][nx] = graph[z][y][x] + 1
                queue.append((nx, ny, nz))

    result = 0
    for z in range(h):
        for y in range(n):
            for x in range(m):
                if graph[z][y][x] == 0:
                    return -1
                result = max(result, graph[z][y][x])
    
    if result == 1 and flag_zero:
        return 0
    return result - 1


m, n, h = map(int, input().split())
graph = [[[int(x) for x in input().split()]
          for _ in range(n)] for _ in range(h)]

print(bfs())