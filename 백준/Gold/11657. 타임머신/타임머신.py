import sys

input = sys.stdin.readline
inf = float("inf")


def bellman_ford(n, edges, start):
    global is_cycle
    dist = [inf] * n
    dist[start] = 0
    for i in range(n+1):
        for u, v, d in edges:
            if dist[u] + d < dist[v]:
                dist[v] = dist[u] + d
                if i == n:
                    is_cycle = True
    return dist


is_cycle = False
v, e = map(int, input().split())
edges = [tuple(map(int, input().split())) for _ in range(e)]
dist = bellman_ford(v+1, edges, 1)
dist = list(map(lambda x: -1 if x == inf else x, dist[2:]))
if is_cycle:
    print(-1)
else:
    print(*dist, sep='\n')
