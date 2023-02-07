import sys

input = sys.stdin.readline


def dfs(start, count):
    visited[start] = True
    count += 1
    if start == b:
        result.append(count)
    for child in graph[start]:
        if not visited[child]:
            dfs(child, count)


n = int(input())
graph = [[] for _ in range(n + 1)]
a, b = map(int, input().split())
m = int(input())
visited = [False] * (n + 1)
result = []

for _ in range(m):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

dfs(a, 0)

if not result:
    print(-1)
else:
    print(result[0] - 1)
