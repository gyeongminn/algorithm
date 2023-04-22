import sys
from heapq import heappop, heappush
input = sys.stdin.readline


def dijkstra(graph, start):
    dist = [sys.maxsize] * len(graph)
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


while True:
    n, m, s, c = map(int, input().split())
    if n == m == s == c == 0:
        break
    graph = [[] for _ in range(n+1)]
    for _ in range(m):
        a, b, v = map(int, input().split())
        graph[a].append((b, v))
    print(dijkstra(graph, s)[c])
