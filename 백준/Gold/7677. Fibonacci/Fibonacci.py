import sys
input = sys.stdin.readline
mod = 10000


def fibonacci(n):
    if n == 0:
        return (0 % mod, 1 % mod)
    else:
        a, b = fibonacci(n // 2)
        c = a * (b * 2 - a)
        d = a * a + b * b
        if n % 2 == 0:
            return (c % mod, d % mod)
        else:
            return (d % mod, (c + d) % mod)


while True:
    n = int(input())
    if n == -1:
        break
    print(fibonacci(n)[0])
