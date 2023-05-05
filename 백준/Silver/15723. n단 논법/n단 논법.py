import sys
from collections import deque
input = sys.stdin.readline

def change(x):
    return ord(x) - ord('a')


def bfs(node, end):
    queue = deque([node])
    visited[node] = True
    while queue:
        node = queue.popleft()
        if node == end:
            return True
        for child in graph[node]:
            if not visited[child]:
                visited[child] = True
                queue.append(child)
    return False

graph = [[] for _ in range(26)]
n = int(input())
for _ in range(n):
    a, _, b = input().split()
    graph[change(a)].append(change(b))

for _ in range(int(input())):
    a, _, b = input().split()
    visited = [False] * 26
    if bfs(change(a), change(b)):
        print('T')
    else:
        print('F')