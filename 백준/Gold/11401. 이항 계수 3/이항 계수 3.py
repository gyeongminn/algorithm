import sys

input = sys.stdin.readline

n, r = map(int, input().split())
p = 1000000007

factorial = [1 for _ in range(n + 1)]
for i in range(2, n + 1):
    factorial[i] = factorial[i - 1] * i % p

print(factorial[n] * pow(factorial[r] * factorial[n - r] % p, p - 2, p) % p)
