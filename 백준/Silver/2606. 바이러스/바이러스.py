from collections import deque


def bfs(v):
    visited = [v]
    queue = deque()
    queue.append(v)
    while queue:
        v = queue.pop()
        for i in graph[v]:
            if i not in visited:
                visited.append(i)
                queue.append(i)
    return visited


n = int(input())  # 컴퓨터의 수
m = int(input())  # 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수

graph = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

result = len(bfs(1)) - 1
print(result)
