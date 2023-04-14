import sys
from heapq import heappop, heappush
input = sys.stdin.readline


def dijkstra(graph, metro, start):
    n = len(graph)
    dist = [float('inf')] * n
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


v, end = map(int, input().split())
graph = [[] for _ in range(v)]
metro = [int(input()) for _ in range(v)]
arr = [[int(x) for x in input().split()] for _ in range(v)]

for i in range(v):
    for j in range(v):
        if arr[i][j] != 0:
            if metro[i] == metro[j]:
                graph[i].append((j, arr[i][j]))
            else:
                graph[i].append((j, arr[i][j] + int(1e6)))
                
res = dijkstra(graph, metro, 0)[end]
print(res // int(1e6), res % int(1e6))
