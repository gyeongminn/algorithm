import sys
from heapq import heappop, heappush
input = sys.stdin.readline


def dijkstra(graph, start):
    n = len(graph)
    dist, parents = [float("inf")] * n, [-1] * n
    dist[start] = 0

    queue = [(0, start)]
    while queue:
        path_len, v = heappop(queue)
        if path_len == dist[v]:
            for w, edge_len in graph[v]:
                if edge_len + path_len < dist[w]:
                    dist[w], parents[w] = edge_len + path_len, v
                    heappush(queue, (edge_len + path_len, w))

    return dist, parents


n, m = map(int, input().split())
visited = [False] * m
graph = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(lambda x: int(x)-1, input().split())
    graph[a].append((b, 1))
    graph[b].append((a, 1))
dist, _ = dijkstra(graph, 0)
max_dist = max(dist)
print(dist.index(max_dist) + 1, max_dist, dist.count(max_dist))
