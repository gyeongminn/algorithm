import sys
input = sys.stdin.readline
mod = 1000000007

def nCr(n, r):
    return fac[n] * pow(fac[r] * fac[n - r] % mod, mod - 2, mod) % mod

fac = [1 for _ in range(10001)]
for i in range(2, 10001):
    fac[i] = fac[i - 1] * i % mod

n, m = map(int, input().split())
ans = 0
for b in range(n // m+1):
    a = n - b *m
    ans += nCr(a+b, b)
print(ans % mod)
