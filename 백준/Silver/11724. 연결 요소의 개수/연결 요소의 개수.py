import sys
input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))


def dfs(node, graph, stack):
    visited[node] = True
    for child in graph[node]:
        if not visited[child]:
            dfs(child, graph, stack)
    stack.append(node)


v, e = map(int, input().split())
graph = [[] for _ in range(v+1)]
graph_inv = [[] for _ in range(v+1)]
for _ in range(e):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph_inv[b].append(a)
    graph[b].append(a)
    graph_inv[a].append(b)

stack = []
visited = [False] * (v+1)
for node in range(1, v+1):
    if not visited[node]:
        dfs(node, graph, stack)

answer = []
visited = [False] * (v+1)
while stack:
    scc = []
    node = stack.pop()
    if not visited[node]:
        dfs(node, graph_inv, scc)
        answer.append(sorted(scc))

print(len(answer))
