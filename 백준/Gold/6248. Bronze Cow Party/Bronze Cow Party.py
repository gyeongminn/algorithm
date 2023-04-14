import sys
from heapq import heappop, heappush
input = sys.stdin.readline
INF = sys.maxsize


def dijkstra(graph, start):
    n = len(graph)
    dist = [INF] * n
    dist[start] = 0
    queue = [(0, start)]
    while queue:
        path_len, v = heappop(queue)
        if path_len == dist[v]:
            for w, edge_len in graph[v]:
                if edge_len + path_len < dist[w]:
                    dist[w] = edge_len + path_len
                    heappush(queue, (edge_len + path_len, w))
    return dist

v, e, x = map(int, input().split())
graph = [[] for _ in range(v+1)]
for _ in range(e):
    a, b, w = map(int, input().split())
    graph[a].append((b, w))
    graph[b].append((a, w))

dist = dijkstra(graph, x)
print(max(dist[1:]) * 2)