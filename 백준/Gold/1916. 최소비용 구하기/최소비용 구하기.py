from heapq import heappop, heappush
import sys
input = sys.stdin.readline


def dijkstra(graph, start):
    n = len(graph)
    dist, parents = [float('inf')] * n, [-1] * n
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


v = int(input().rstrip())
e = int(input().rstrip())
graph = [[] for _ in range(v)]
for _ in range(e):
    a, b, w = map(int, input().rstrip().split())
    graph[a-1].append((b-1, w))
start, end = map(int, input().rstrip().split())

dist, parents = dijkstra(graph, start-1)
print(dist[end-1])
