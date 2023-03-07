import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 4)


def dfs(node):
    if visited[node] > 1:
        return False
    visited[node] += 1
    for next in graph[node]:
        if not selected[next] or dfs(selected[next]):
            selected[next] = node
            return True
    return False


n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]
for i in range(1, n+1):
    graph[i] = [int(x) for x in input().split()][1:]

selected = [0] * (m+1)
for _ in range(2):
    for i in range(1, n+1):
        visited = [0] * (n+1)
        dfs(i)


count = 0
for i in range(1, m+1):
    if selected[i] > 0:
        count += 1

print(count)
