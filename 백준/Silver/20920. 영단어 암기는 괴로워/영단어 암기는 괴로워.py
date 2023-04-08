from collections import defaultdict
from functools import cmp_to_key
import sys
input = sys.stdin.readline


def compare(x, y):
    if dic[x] < dic[y]:
        return 1
    if dic[x] > dic[y]:
        return -1
    if len(x) < len(y):
        return 1
    if len(x) > len(y):
        return -1
    if x > y:
        return 1
    return -1


n, m = map(int, input().split())
dic = defaultdict(int)
arr = []
for _ in range(n):
    name = input().rstrip()
    if len(name) < m:
        continue
    arr.append(name)
    dic[name] += 1
arr = sorted(set(arr), key=cmp_to_key(compare))
print(*arr, sep='\n')
