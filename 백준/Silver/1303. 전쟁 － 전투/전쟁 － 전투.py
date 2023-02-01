from collections import deque


def bfs(x, y, team):
    if graph[y][x] != team or visited[y][x]:
        return 0

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    count = 0
    queue = deque()
    queue.append((x, y))
    visited[y][x] = True

    while queue:
        x, y = queue.popleft()
        count += 1

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if not (0 <= nx < n and 0 <= ny < m) or visited[ny][nx] or graph[ny][nx] != team:
                continue

            visited[ny][nx] = True
            queue.append((nx, ny))

    return count ** 2


n, m = map(int, input().split())
graph = [list(input()) for _ in range(m)]
visited = [[False] * n for _ in range(m)]
blue, white = 0, 0

for y in range(m):
    for x in range(n):
        blue += bfs(x, y, 'B')
        white += bfs(x, y, 'W')

print(white, blue)
