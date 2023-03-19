import sys
input = sys.stdin.readline


def a_to_ten(arr):
    res = 0
    for i, item in enumerate(arr):
        res += item * pow(a, i)
    return res


def ten_to_b(n):
    res = []
    while n:
        res.append(n % b)
        n //= b
    return res[::-1]


a, b = map(int, input().split())
m = int(input())
arr = [int(x) for x in input().split()]
print(*ten_to_b(a_to_ten(arr[::-1])))
