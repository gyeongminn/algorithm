from heapq import heappop, heappush
from collections import deque
import sys

input = sys.stdin.readline
inf = float('inf')


def dijkstra(graph, start, visited):
    n = len(graph)
    dist = [inf] * n
    dist[start] = 0
    queue = [(0, start)]
    while queue:
        path_len, v = heappop(queue)
        if path_len == dist[v]:
            for w, edge_len in graph[v]:
                if visited[v][w]:
                    continue
                if edge_len + path_len < dist[w]:
                    dist[w] = edge_len + path_len
                    heappush(queue, (edge_len + path_len, w))
    return dist


def bfs(start, end, graph, dist, visited):
    queue = deque([start])
    while queue:
        node = queue.popleft()
        if node == end:
            continue
        for v, w in graph[node]:
            if dist[v] + w == dist[node] and not visited[v][node]:
                visited[v][node] = True
                queue.append(v)
    return visited


while True:
    v, e = map(int, input().split())
    if not v:
        break
    s, d = map(int, input().split())
    graph = [[] for _ in range(v)]
    graph_inv = [[] for _ in range(v)]
    visited = [[False] * v for _ in range(v)]
    for _ in range(e):
        a, b, w = map(int, input().split())
        graph[a].append([b, w])
        graph_inv[b].append([a, w])
    dist1 = dijkstra(graph, s, visited)
    bypass = bfs(d, s, graph_inv, dist1, visited)
    dist2 = dijkstra(graph, s, bypass)
    res = dist2[d]
    if res == inf:
        res = -1
    print(res)
