import sys

input = sys.stdin.readline
p = 1000000007

m = int(input())
query = [[int(x) for x in input().split()] for _ in range(m)]

max_n = max(query, key=lambda x: x[0])[0]
factorial = [1 for _ in range(max_n + 1)]
for i in range(2, max_n + 1):
    factorial[i] = factorial[i - 1] * i % p

for n, r in query:
    print(factorial[n] * pow(factorial[r] *
          factorial[n - r] % p, p - 2, p) % p)
