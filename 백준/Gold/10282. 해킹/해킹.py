from heapq import heappop, heappush
import sys
input = sys.stdin.readline
INF = sys.maxsize

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


t = int(input())
for _ in range(t):
    v, e, start = map(int, input().split())
    graph = [[] for _ in range(v)]
    for _ in range(e):
        b, a, w = map(int, input().rstrip().split())
        graph[a-1].append((b-1, w))
    result, count = 0, 0
    for d in dijkstra(graph, start-1):
        if d != INF:
            if result < d:
                result = d
            count += 1
    print(count, result)
