from collections import deque


def bfs(x, y):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    queue = deque()
    queue.append((x, y))
    
    cnt_v = 0
    cnt_k = 0

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if not (0 <= nx < c and 0 <= ny < r):
                continue
            
            if visited[ny][nx] or graph[ny][nx] == '#':
                continue
            
            visited[ny][nx] = True
            
            if graph[ny][nx] == 'v':
                cnt_v += 1
            elif graph[ny][nx] == 'k':
                cnt_k += 1
            
            queue.append((nx, ny))
            
    if cnt_k > cnt_v:
        cnt_v = 0
    else:
        cnt_k = 0
        
    return cnt_k, cnt_v
            


r, c = map(int, input().split())
graph = [[] for _ in range(r)]
visited = [[False] * c for _ in range(r)]
result = [0, 0]

for y in range(r):
    graph[y] = list(input())

for y in range(r):
    for x in range(c):
        if not visited[y][x]:
            cnt_k, cnt_v = bfs(x, y)
            result[0] += cnt_k
            result[1] += cnt_v

print(*result)