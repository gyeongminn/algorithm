import sys
from math import ceil, log
input = sys.stdin.readline

n, q = map(int, input().split())
arr = [int(x) for x in input().split()]


def segment(left, right, idx=1):
    if left == right:
        tree[idx] = arr[left]
        return tree[idx]
    mid = (left + right) // 2
    tree[idx] = segment(left, mid, idx*2) + segment(mid+1, right, idx*2+1)
    return tree[idx]


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
segment(0, n-1)

for _ in range(q):
    x, y, a, b = map(int, input().split())
    x, y, a = x - 1, y - 1, a - 1
    if x > y:
        x, y = y, x
    print(search(x, y))
    update(a, b - arr[a])
    arr[a] = b
