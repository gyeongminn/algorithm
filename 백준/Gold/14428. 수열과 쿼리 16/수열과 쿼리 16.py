import sys
from math import ceil, log2

input = sys.stdin.readline
INF = sys.maxsize
UPDATE = 1
FIND_MIN = 2


def update(node, start, end, index, new):
    if index < start or end < index:
        return [INF, INF]
    if start == end:
        segtree[node] = new
        return
    mid = (start + end) // 2
    update(node*2, start, mid, index, new)
    update(node*2+1, mid+1, end, index, new)
    segtree[node] = min(segtree[node*2], segtree[node*2+1])


def find_min(node, start, end, left, right):
    if right < start or left > end:
        return [INF, INF]

    if left <= start and right >= end:
        return segtree[node]

    mid = (start + end) // 2
    return min(find_min(node*2, start, mid, left, right), find_min(node*2+1, mid+1, end, left, right))


n = int(input())
arr = [int(x) for x in input().split()]

size = 2 ** ceil(log2(n))
segtree = [[0, 0]] * (size * 2)

for i in range(n):
    segtree[size+i] = [arr[i], i+1]
for i in range(size-1, 0, -1):
    segtree[i] = min(segtree[i*2], segtree[i*2+1])

m = int(input())
for _ in range(m):
    option, a, b = map(int, input().split())
    if option == UPDATE:
        update(1, 1, size, a, [b, a])
    elif option == FIND_MIN:
        print(find_min(1, 1, size, a, b)[1])
