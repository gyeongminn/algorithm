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


n, v, e = map(int, input().split())
av, bv = map(int, input().split())
arr = [int(x) for x in input().split()]
graph = [[] for _ in range(v+1)]
for _ in range(e):
    a, b, w = map(int, input().split())
    graph[a].append((b, w))
    graph[b].append((a, w))
dist1 = dijkstra(graph, av)
dist2 = dijkstra(graph, bv)

result = 0
for i in arr:
    d1, d2 = dist1[i], dist2[i]
    if d1 == float('inf'):
        d1 = -1
    if d2 == float('inf'):
        d2 = -1
    result += d1 + d2
print(result)