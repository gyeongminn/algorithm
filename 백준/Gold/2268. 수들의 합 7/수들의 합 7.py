import sys
from math import ceil, log
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [0] * n


def search(left, right, start=0, end=n-1, idx=1):
    if end < left or start > right:
        return 0
    if left <= start and end <= right:
        return tree[idx]
    mid = (start + end) // 2
    return search(left, right, start, mid, idx*2) + search(left, right, mid+1, end, idx*2+1)


def update(node, diff, start=0, end=n-1, idx=1):
    if start > node or node > end:
        return
    tree[idx] += diff
    if start != end:
        mid = (start + end) // 2
        update(node, diff, start, mid, idx*2)
        update(node, diff, mid+1, end, idx*2+1)


tree = [0] * 2**(ceil(log(n, 2) + 1))

for _ in range(m):
    opt, a, b = map(int, input().split())
    if opt:
        update(a-1, b - arr[a-1])
        arr[a-1] = b
    else:
        if a > b:
            a, b = b, a
        print(search(a-1, b-1))
