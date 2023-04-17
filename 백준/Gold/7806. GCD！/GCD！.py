import math
import random
import sys

input = sys.stdin.readline
prime_numbers = [2, 3, 5, 7, 11, 13, 17, 19, 23]


def miller_rabin(n, check):
    if n == check:
        return True
    d = n - 1
    while d % 2 == 0:
        if pow(check, d, n) == n - 1:
            return True
        d //= 2
    x = pow(check, d, n)
    return x == 1 or x == n - 1


def is_prime(n):
    if n <= 1:
        return False
    for prime in prime_numbers:
        if not miller_rabin(n, prime):
            return False
    return True


def pollard_rho(n):
    if is_prime(n) or n == 1:
        return n
    if n % 2 == 0:
        return 2

    x = random.randrange(2, n)
    y = x
    c = random.randrange(1, n)
    d = 1

    while d == 1:
        x = ((x * x % n) + c + n) % n
        y = ((y * y % n) + c + n) % n
        y = ((y * y % n) + c + n) % n
        d = math.gcd(abs(x - y), n)
        if d == n:
            return pollard_rho(n)
    if is_prime(d):
        return d
    return pollard_rho(d)


def factor(n):
    result = []
    while n > 1:
        d = pollard_rho(n)
        result.append(d)
        n //= d
    return result


while True:
    try:
        n, m = map(int, input().split())
        factors = factor(m)
        factors_set = set(factors)
        res = 1
        for p in factors_set:
            m_count = factors.count(p)
            tmp = n
            n_count = 0
            while tmp // p:
                tmp //= p
                n_count += tmp
                if n_count >= m_count:
                    break
            res *= pow(p, min(m_count, n_count))
        print(res)
    except:
        break
