from collections import deque
import sys
input = sys.stdin.readline


def bfs(start, end):
    queue = deque([start])
    while queue:
        x = queue.popleft()
        if x == end:
            return visited[x]
        for nx in [x-1, x+1, x*2]:
            if 0 <= nx <= 100000 and visited[nx] == 0:
                visited[nx] = visited[x] + 1
                queue.append(nx)


n, k = map(int, input().split())
visited = [0] * 100001
print(bfs(n, k))
