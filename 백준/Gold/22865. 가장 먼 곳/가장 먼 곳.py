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

n = int(input())
graph = [[] for _ in range(n+1)]
va, vb, vc = map(int, input().split())
m = int(input())
for _ in range(m):
    a, b, w = map(int, input().split())
    graph[a].append((b, w))
    graph[b].append((a, w))
    
da = dijkstra(graph, va)
db = dijkstra(graph, vb)
dc = dijkstra(graph, vc)

res = [0, 0]
for i in range(1, n+1):
    tot = max(res[1], min(da[i], db[i], dc[i]))
    if res[1] < tot:
        res = [i, tot]
print(res[0])