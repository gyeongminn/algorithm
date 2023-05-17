import sys
input = sys.stdin.readline
mod = 1000000007


def make_nCr_mod(max_n, mod):
    fac = [1 for _ in range(max_n+1)]
    for i in range(2, max_n+1):
        fac[i] = fac[i - 1] * i % mod
        
    def nCr_mod(n, r):
        return fac[n] * pow(fac[r] * fac[n - r] % mod, mod - 2, mod) % mod
    
    return nCr_mod


nCr = make_nCr_mod(10000, 1000000007)
n, m = map(int, input().split())
ans = 0

for b in range(n // m+1):
    a = n - b * m
    ans += nCr(a+b, b)
    
print(ans % mod)
