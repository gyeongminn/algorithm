import sys
input = sys.stdin.readline

def fibonacci(n):
    if n == 0:
        return (0, 1)
    else:
        a, b = fibonacci(n // 2)
        c = a * (b * 2 - a)
        d = a * a + b * b
        if n % 2 == 0:
            return (c % mod, d % mod)
        else:
            return (d % mod, (c + d) % mod)
        
mod = int(1e9)
for _ in range(int(input())):
    print(fibonacci(int(input()))[0])