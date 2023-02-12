import sys
import random

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

    for i in range(5):
        a = random.randint(2, n - 1)
        if try_composite(a):
            return False

    return True


def is_palindrome(num):
    num_str = str(num)
    return num_str == num_str[::-1]


n = int(input())
for num in range(n, 100000000):
    if is_palindrome(num) and is_prime(num):
        print(num)
        break
