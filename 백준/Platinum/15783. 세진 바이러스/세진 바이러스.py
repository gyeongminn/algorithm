import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)


def dfs(node, graph, stack):
    visited[node] = True
    for child in graph[node]:
        if not visited[child]:
            dfs(child, graph, stack)
    stack.append(node)


v, e = map(int, input().split())
graph = [[] for _ in range(v)]
graph_inv = [[] for _ in range(v)]
for _ in range(e):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph_inv[b].append(a)

stack = []
visited = [False] * v
for node in range(v):
    if not visited[node]:
        dfs(node, graph, stack)

visited = [False] * v
count = 0
while stack:
    scc = []
    node = stack.pop()
    if not visited[node]:
        dfs(node, graph, scc)
        count+= 1

print(count)
