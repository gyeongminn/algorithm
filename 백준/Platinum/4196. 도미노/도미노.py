import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)


def dfs(node, graph, stack):
    visited[node] = True
    for child in graph[node]:
        if not visited[child]:
            dfs(child, graph, stack)
    stack.append(node)


t = int(input())
for _ in range(t):
    v, e = map(int, input().split())
    graph = [[] for _ in range(v+1)]
    graph_inv = [[] for _ in range(v+1)]
    for _ in range(e):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph_inv[b].append(a)

    stack = []
    visited = [False] * (v+1)
    for node in range(1, v+1):
        if not visited[node]:
            dfs(node, graph, stack)

    visited = [False] * (v+1)
    count = 0
    while stack:
        scc = []
        node = stack.pop()
        if not visited[node]:
            dfs(node, graph, scc)
            count+= 1

    print(count)
