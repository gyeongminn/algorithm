import sys
input = sys.stdin.readline

n = int(input())
arr = list(input().split())
dp = [[0] * n for _ in range(n)]

for i in range(n):
    for start in range(n - i):
        end = start + i
        if start == end:
            dp[start][end] = 1
        elif arr[start] == arr[end]:
            if end - start == 1 or dp[start+1][end-1] == 1:
                dp[start][end] = 1

m = int(input())
for _ in range(m):
    s, e = map(int, input().split())
    print(dp[s-1][e-1])
