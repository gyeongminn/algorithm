import sys
input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))


def true(x):
    return 2 * x


def false(x):
    return 2 * x + 1


def dfs(node):
    visited[node] = True
    for child in graph[node]:
        if not visited[child]:
            dfs(child)
    stack.append(node)


def dfs_rev(node, idx):
    visited[node] = True
    scc[node] = idx
    for child in graph_rev[node]:
        if not visited[child]:
            dfs_rev(child, idx)


while True:
    s  = input()
    if s == "":
        break
    v, e = map(int, s.split())
    scc = [0] * (2*(v+1))
    graph = [[] for _ in range(2*(v+1))]
    graph_rev = [[] for _ in range(2*(v+1))]
    for _ in range(e):
        a, b = map(int, input().split())
        a = true(a) if a > 0 else false(-a)
        b = true(b) if b > 0 else false(-b)
        graph[a ^ 1].append(b)
        graph[b ^ 1].append(a)
        graph_rev[b].append(a ^ 1)
        graph_rev[a].append(b ^ 1)

    stack = []
    visited = [False] * (2*(v+1))
    for node in range(2, 2*(v+1)):
        if not visited[node]:
            dfs(node)

    idx = 1
    visited = [False] * (2*(v+1))
    while stack:
        node = stack.pop()
        if not visited[node]:
            dfs_rev(node, idx)
            idx += 1

    result = [0] * v
    flag = False
    for node in range(1, v+1):
        if scc[true(node)] == scc[false(node)]:
            flag = True
    if not flag and scc[true(1)] > scc[false(1)]:
        print('yes')
    else:
        print('no')