import sys
input = sys.stdin.readline


def nCr(n, r):
    return fac[n] * pow(fac[r] * fac[n - r] % mod, mod - 2, mod) % mod


mod = 1000000007

fac = [1 for _ in range(10000)]
for i in range(2, 10000):
    fac[i] = fac[i - 1] * i % mod

t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    if a > b:
        a, b = b, a
    print(nCr(b, a))
