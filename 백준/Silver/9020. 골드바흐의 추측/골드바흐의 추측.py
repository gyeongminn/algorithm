import sys


def is_prime(n):
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True


t = int(sys.stdin.readline())
for _ in range(t):
    num = int(sys.stdin.readline())
    a = num // 2
    b = a
    while (not is_prime(a)) or (not is_prime(b)):
        a -= 1
        b += 1
    print(a, b)