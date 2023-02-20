# 참고 : https://blog.naver.com/PostView.naver?blogId=jinhan814&logNo=222504883134
import sys
import random
import math
from bisect import bisect_left

input = sys.stdin.readline


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


while True:
    n = int(input())

    if n == 0:
        break

    factors = []
    factors = get_factors(n)
    length = len(factors)
    if len(factors) < 4:
        print(sum(factors) + 3 - length)
        continue

    factors.sort()
    divisors = [1]

    if len(set(factors)) == 1:
        factor = list(set(factors))[0]
        k1 = k2 = k3 = len(factors) // 3
        if len(factors) % 3 == 1:
            k1 += 1
        elif len(factors) % 3 == 2:
            k1 += 1
            k2 += 1
        print(sum([pow(factor, k1), pow(factor, k2), pow(factor, k3)]))
        continue

    for factor in factors:
        for i in range(len(divisors)):
            divisors.append(divisors[i] * factor)
    divisors = sorted(list(set(divisors)))

    result = sys.maxsize
    for divisor in divisors:
        idx = bisect_left(divisors, math.sqrt(divisor))
        for i in range(idx - 3, idx + 4):
            if i in range(len(divisors)) and not divisor % divisors[i]:
                result = min(result, n // divisor + divisor // divisors[i] + divisors[i])

    print(result)
