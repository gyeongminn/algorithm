import sys

input = sys.stdin.readline
test_case = [int(input()) for _ in range(int(input()))]

dp = [0 for _ in range(12)]
dp[1:5] = 1, 2, 4, 7

for i in range(5, 12):
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3]

for n in test_case:
    print(dp[n])