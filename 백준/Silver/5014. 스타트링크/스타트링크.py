import sys
from collections import deque

input = sys.stdin.readline


def bfs(start):
    queue = deque([start])
    while queue:
        floor = queue.popleft()
        if floor == g:
            break
        for move in [u, -d]:
            new_floor = floor + move
            if new_floor == floor:
                continue
            if 0 < new_floor <= f and graph[new_floor] == 0:
                graph[new_floor] = graph[floor] + 1
                queue.append(new_floor)
    else :
        print('use the stairs')
        exit(0)

f, s, g, u, d = map(int, input().split())
graph = [0] * (f + 1)
bfs(s)

print(graph[g])
