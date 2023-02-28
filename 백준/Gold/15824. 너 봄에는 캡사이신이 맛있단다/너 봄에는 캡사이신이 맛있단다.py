import sys

input = sys.stdin.readline
MOD = 1000000007

n = int(input())
arr = sorted([int(x) for x in input().split()])

result = 0
for i in range(len(arr)):
    result += arr[i] * pow(2, i) - arr[i] * pow(2, n-i-1)
    result %= MOD
print(result)
