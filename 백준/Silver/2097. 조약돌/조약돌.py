import sys
from math import *


def solution(n):
    if n < 5:
        return 4
    c = ceil(sqrt(n))
    r = ceil(n / c)
    return (r + c - 2) * 2


input = sys.stdin.readline
n = int(input())
print(solution(n))
