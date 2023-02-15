import sys
from functools import cmp_to_key

input = sys.stdin.readline


def compare(a, b):
    if len(a) < len(b):
        return -1
    elif len(a) > len(b):
        return 1
    if a < b:
        return -1
    else:
        return 1


n = int(input())
words = [input().rstrip() for _ in range(n)]
print(*sorted(set(words), key=cmp_to_key(compare)), sep='\n')
