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
    return dist


v, e = map(int, input().split())
graph = [[] for _ in range(v)]
for _ in range(e):
    a, b, w = map(int, input().rstrip().split())
    graph[a-1].append((b-1, w))
    graph[b-1].append((a-1, w))
v1, v2 = map(int, input().split())

dist = dijkstra(graph, 0)
result1 = dist[v1-1], dijkstra(graph, v1-1)[v2-1], dijkstra(graph, v2-1)[v-1]
result2 = dist[v2-1], dijkstra(graph, v2-1)[v1-1], dijkstra(graph, v1-1)[v-1]
if float('inf') in result1 and result2:
    print(-1)
else:
    print(min(sum(result1), sum(result2)))