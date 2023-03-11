def solution(x):
    if x == 0:
        return 1
    if x == 1:
        return (r + 1) % mod
    if x % 2 == 1:
        return solution(x // 2) * (1 + pow(r, x // 2 + 1, mod)) % mod
    else:
        return (solution(x // 2 - 1) * (1 + pow(r, x // 2, mod)) + pow(r, x, mod)) % mod


a, r, n, mod = map(int, input().split())
print(a * solution(n - 1) % mod)
