import sys

input = sys.stdin.readline

n = int(input())
graph = [[int(x) for x in input().split()] for _ in range(n)]

for i in range(n):
    for j in range(n):
        for k in range(n):
            if graph[j][i] and graph[i][k]:
                graph[j][k] = 1

for row in graph:
    print(*row)
