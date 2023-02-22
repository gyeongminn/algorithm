import math
import random
from collections import Counter
import sys

input = sys.stdin.readline
prime_numbers = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997]


def miller_rabin(n, check):
    d = n - 1
    while d % 2 == 0:
        if pow(check, d, n) == n - 1:
            return True
        d //= 2
    x = pow(check, d, n)
    return x == 1 or x == n - 1


def is_prime(n):
    if n < 2 or n % 2 == 0:
        return False
    for prime in prime_numbers:
        if n == prime:
            return True
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


def is_one_square(n):
    return int(math.sqrt(n)) ** 2 == n


def is_four_square(n):
    while n % 4 == 0:
        n //= 4
    return n % 8 == 7


def is_three_square(n):
    for f, i in Counter(factor(n)).items():
        if (f - 3) % 4 == 0 and i % 2 == 1:
            return True
    return False


def solution(n):
    if is_four_square(n):
        return 4
    if is_three_square(n):
        return 3
    if is_one_square(n):
        return 1
    return 2


print(solution(int(input())))
