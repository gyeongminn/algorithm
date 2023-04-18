import sys
from heapq import heappop, heappush
input = sys.stdin.readline


def dijkstra(graph, start):
    n = len(graph)
    dist = [float("inf")] * n
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


v = int(input())
end = int(input())
time = int(input())
e = int(input())
graph = [[] for _ in range(v+1)]
for _ in range(e):
    a, b, w = map(int, input().split())
    graph[a].append((b, w))

count = 0
for i in range(1, v+1):
    if dijkstra(graph, i)[end] <= time:
        count += 1
print(count)
