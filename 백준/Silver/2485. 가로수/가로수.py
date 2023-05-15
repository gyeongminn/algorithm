import sys
from math import *
input = sys.stdin.readline


n = int(input())
arr = [int(input()) for _ in range(n)]

diff = [arr[i] - arr[i-1] for i in range(1, n)]
g = diff[0]
for i in range(1, n-1):
    g = gcd(g, diff[i])

ans = 0
for d in diff:
    ans += d // g - 1
print(ans)