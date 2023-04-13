from heapq import heappop, heappush


def dijkstra(graph, start):
    dist = [float('inf')] * (10001)
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

e, d= map(int, input().split())
graph = [[] for _ in range(10001)]
for i in range(10000):
    graph[i].append((i+1, 1))
for _ in range(e):
    a, b, w = map(int, input().split())
    graph[a].append((b, w))
print(dijkstra(graph, 0)[d])