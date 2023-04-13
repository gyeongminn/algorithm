import sys
from heapq import heappop, heappush
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


T = int(input())
for _ in range(T):
    v, e, t = map(int, input().split())
    s, g, h = map(int, input().split())
    graph = [[] for _ in range(v)]
    for _ in range(e):
        a, b, d = map(int, input().split())
        if (a == g and b == h) or (b == g and a == h):
            d -= 0.01
        graph[a-1].append((b-1, d))
        graph[b-1].append((a-1, d))
    target = [int(input()) for _ in range(t)]
    dist, parents = dijkstra(graph, s-1)
    target.sort()
    for i in target:
        if dist[i-1] != float('inf') and type(dist[i-1]) == float:
            print(i, end=' ')
    print()