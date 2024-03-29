import sys
input = sys.stdin.readline


def solution(n):
    phi = int(n > 0 and n)
    for p in range(2, int(n ** 0.5) + 1):
        if not n % p:
            phi -= phi // p
            while not n % p:
                n //= p
    if n > 1:
        phi -= phi // n
    return phi


print(solution(int(input())))
