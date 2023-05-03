import sys
import math
import random
from bisect import bisect_left, bisect_right

input = sys.stdin.readline
prime_numbers = [2, 3, 5, 7, 11, 13, 17, 19, 23]


def is_prime(n):
    if n <= 1 or n == 4:
        return False
    if n <= 3:
        return True

    d = n - 1
    s = 0
    while d % 2 == 0:
        d //= 2
        s += 1

    def try_composite(a):
        if pow(a, d, n) == 1:
            return False
        for i in range(s):
            if pow(a, 2**i * d, n) == n - 1:
                return False
        return True

    for _ in range(5):
        a = random.randint(2, n - 1)
        if try_composite(a):
            return False

    return True


def pollard_rho(n):
    def g(x):
        return (x * x + 1) % n

    start_x, start_y, d = 2, 2, 1
    for k in range(2, 11):
        x = pow(start_x, k)
        y = pow(start_y, k)
        while d == 1:
            x = g(x)
            y = g(g(y))
            d = math.gcd(abs(x - y), n)
        if 1 < d < n:
            return d
    return d


def factorize(n):
    result = []
    factor = 2
    while factor ** 2 <= n:
        while n % factor == 0:
            result.append(factor)
            n = n // factor
        factor += 1
    if n > 1:
        result.append(n)
    return result


def get_factors(n):
    result = []
    while n != 1:
        if is_prime(n):
            result.append(n)
            break
        k = pollard_rho(n)
        result.append(int(k))
        n = n // k
    for _ in range(len(result)):
        for x in result:
            if not is_prime(x):
                result.remove(x)
                result.extend(factorize(x))
    return result


fib = [0, 1, 1]
for _ in range(100):
    fib.append(fib[-1] + fib[-2])

while True:
    try:
        a, b = input().split()
        a, b = int(a, 16), int(b, 16)
        if a >= b:
            break
    except:
        break
    print(f'Range {a} to {b}:')
    left, right = bisect_left(fib, a), bisect_right(fib, b)
    if left == right:
        print('No Fibonacci numbers in the range')
    for i in range(left, right):
        if i == 0:
            print('Fib(0) = 0, lg does not exist')
        else:
            print(f'Fib({i}) = {fib[i]}, lg is {math.log2(fib[i]):.6f}')
        prime = factorize(fib[i])
        if not prime:
            print('No prime factors')
        else:
            print('Prime factors:', *prime)
    print()
