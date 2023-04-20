from heapq import heappop, heappush
from itertools import permutations
import os, io, sys
input = sys.stdin.readline
INF = float('inf')


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


n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]
for _ in range(m):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))
    graph[v].append((u, w))
x, z = map(int, input().split())
p = int(input())
mid = [int(x) for x in input().split()]

dist = {}
for node in mid:
    dist[node] = dijkstra(graph, node)
dist[x] = dijkstra(graph, x)

result = INF
for a, b, c in permutations(mid, 3):
    total = dist[x][a] + dist[a][b] + dist[b][c] + dist[c][z]
    if result > total:
        result = total
if result == INF:
    result = -1
print(result)
