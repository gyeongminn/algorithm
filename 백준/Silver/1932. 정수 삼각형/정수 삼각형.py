import sys

input = sys.stdin.readline

n = int(input())
dp = [[int(x) for x in input().split()] for _ in range(n)]

for y in range(n):
    for x in range(y+1):
        max_parent = 0
        for dx in [-1, 0]:
            nx = x + dx
            if not nx in range(y):
                continue
            max_parent = max(max_parent, dp[y-1][nx])
        dp[y][x] = dp[y][x] + max_parent

print(max(dp[-1]))
