from collections import deque


def bfs(x, y):
    move = [(1, 0), (0, 1), (-1, 0), (0, -1)]

    queue = deque()
    queue.append((x, y))

    while queue:
        x, y = queue.popleft()
        
        for d in move:
            new_x = x + d[0]
            new_y = y + d[1]
            
            if 0 <= new_x < m and 0 <= new_y < n and graph[new_y][new_x] == 1:
                queue.append((new_x, new_y))
                graph[new_y][new_x] = graph[y][x] + 1
            
    return graph[n-1][m-1]


n, m = map(int, input().split())
graph = [list(map(int, list(input()))) for _ in range(n)]

print(bfs(0, 0))
