import sys

sys.setrecursionlimit(10 ** 9)
input = sys.stdin.readline


def dfs(start):
    visited[start] = True
    for child in graph[start]:
        if not visited[child]:
            dfs(child)
            dp[start][1] += min(dp[child][0], dp[child][1])
            dp[start][0] += dp[child][1]
    dp[start][1] += 1


n = int(input())
dp = [[0, 0] for _ in range(n)]
graph = [[] for _ in range(n)]
visited = [False] * n
for _ in range(n-1):
    a, b = map(int, input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

dfs(0)
print(min(dp[0][0], dp[0][1]))
