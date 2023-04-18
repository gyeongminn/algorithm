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


v, e, x, y = map(int, input().split())
graph = [[] for _ in range(v)]
for _ in range(e):
    a, b, w = map(int, input().split())
    graph[a].append((b, w))
    graph[b].append((a, w))
    
dists = sorted(dijkstra(graph, y))

if dists[-1] * 2 > x:
        print(-1)
        exit(0)
        
count = 1
cur = x
for d in dists:
    if cur >= 2 * d:
        cur -= 2 * d
    else:
        cur = x
        cur -= 2 * d
        count += 1
print(count)