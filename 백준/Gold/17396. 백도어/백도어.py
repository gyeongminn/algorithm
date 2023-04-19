import sys
from heapq import heappop, heappush
input = sys.stdin.readline


def dijkstra(graph, start, arr):
    dist = [float('inf')] * len(graph)
    dist[start] = 0
    queue = [(0, start)]
    while queue:
        path_len, v = heappop(queue)
        if arr[v] and v != len(graph)-1:
            continue
        if path_len == dist[v]:
            for w, edge_len in graph[v]:
                if edge_len + path_len < dist[w]:
                    dist[w] = edge_len + path_len
                    heappush(queue, (edge_len + path_len, w))
    return dist


v, e = map(int, input().split())
arr = [int(x) for x in input().split()]
graph = [[] for _ in range(v)]
for _ in range(e):
    a, b, w = map(int, input().split())
    graph[a].append((b, w))
    graph[b].append((a, w))
dist = dijkstra(graph, 0, arr)[v-1]
print(dist if dist != float('inf') else -1)