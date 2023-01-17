import sys

input = sys.stdin.readline

t = int(input())

dp = [0 for _ in range(101)]
dp[1:10] = 1, 1, 1, 2, 2, 3, 4, 5, 7, 9

for i in range(11, 101):
    dp[i] = dp[i-5] + dp[i-1]

for _ in range(t):
    n = int(input())
    print(dp[n])
