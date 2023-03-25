import sys
from heapq import heappop, heappush
input = sys.stdin.readline


def dijkstra(graph, start):
    length = len(graph)
    dist, parents = [float("inf")] * length, [-1] * length
    dist[start] = 0
    queue = [(0, start)]
    while queue:
        path_len, v = heappop(queue)
        if path_len == dist[v]:
            for w in graph[v]:
                edge_len = 1
                if edge_len + path_len < dist[w]:
                    dist[w], parents[w] = edge_len + path_len, v
                    heappush(queue, (edge_len + path_len, w))
    return dist, parents


n, m, k, x = map(int, input().split())

graph = [[] for _ in range(n+1)]
for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)

dist, parents = dijkstra(graph, x)

flag = True
for i, d in enumerate(dist):
    if d == k:
        print(i)
        flag = False
if flag:
    print(-1)
