import sys
from itertools import permutations
from heapq import heappop, heappush

input = sys.stdin.readline
INF = float('inf')


def dijkstra(graph, start):
    dist = [INF] * len(graph)
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
    v, e = map(int, input().split())
    graph = [[] for _ in range(v)]
    for _ in range(e):
        a, b, w = map(int, input().split())
        graph[a].append((b, w))
        graph[b].append((a, w))
    s = int(input())
    mid = [int(input()) for _ in range(s)]

    dist = {}
    for node in mid:
        dist[node] = dijkstra(graph, node)
    dist[0] = dijkstra(graph, 0)

    result = INF
    for tmp in permutations(mid, s):
        total = 0
        tmp = [0] + list(tmp) + [0]
        for i in range(1, s+2):
            total += dist[tmp[i-1]][tmp[i]]
        result = min(result, total)
    print(result)
