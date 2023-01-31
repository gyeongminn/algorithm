from collections import deque


def dfs(start):
    visited[start] = True
    answer.append(start)

    for child in graph[start]:
        if not visited[child]:
            dfs(child)


def bfs(start):
    queue = deque([start])
    visited[start] = True

    while queue:
        node = queue.popleft()
        answer.append(node)
        for child in graph[node]:
            if not visited[child]:
                visited[child] = True
                queue.append(child)


n, m, v = map(int, input().split())
graph = [[] for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    
for node in graph:
    node.sort()

answer = []
visited = [False] * (n+1)
dfs(v)
print(*answer)

visited = [False] * (n+1)
answer = []
bfs(v)
print(*answer)
