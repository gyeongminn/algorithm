import sys
from heapq import heappop, heappush
input = sys.stdin.readline


def dijkstra(graph, start):
    dist = [float('inf')] * len(graph)
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


v, k = map(int, input().split())
graph = [[] for _ in range(v+1)]
for _ in range(k):
    opt, *item = map(int, input().split())
    if opt == 1:
        a, b, w = item
        graph[a].append((b, w))
        graph[b].append((a, w))
    else:
        a, b = item
        dist = dijkstra(graph, a)[b]
        if dist == float('inf'):
            dist = -1
        print(dist)
