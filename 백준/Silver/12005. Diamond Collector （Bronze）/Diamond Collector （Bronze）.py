import sys
from bisect import bisect_right

input = sys.stdin.readline

n, k = map(int, input().split())
dominos = sorted([int(input()) for _ in range(n)])

result = 0
for i, domino in enumerate(dominos):
    result = max(result, bisect_right(dominos, domino + k) - i)

print(result)