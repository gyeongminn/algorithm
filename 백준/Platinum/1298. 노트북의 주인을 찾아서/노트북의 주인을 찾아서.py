import sys
input = sys.stdin.readline


def dfs(node):
    if visited[node]:
        return False
    visited[node] = True
    for next in graph[node]:
        if not selected[next] or dfs(selected[next]):
            selected[next] = node
            return True
    return False


n, m = map(int, input().split())
graph = [[] for _ in range(101)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)

count = 0
selected = [0] * (5001)
for i in range(1, n+1):
    visited = [False] * (5001)
    if dfs(i):
        count += 1
        
print(count)
