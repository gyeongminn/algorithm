import sys
from math import ceil, log
input = sys.stdin.readline

n, q = map(int, input().split())
arr = [0] * n


def init(left=0, right=n-1, idx=1):
    if left == right:
        tree[idx] = arr[left]
        return tree[idx]
    mid = (left + right) // 2
    tree[idx] = init(left, mid, idx*2) + init(mid+1, right, idx*2+1)
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
init()

for _ in range(q):
    opt, a, b = map(int, input().split())
    if opt == 2:
        print(search(a-1, b-1))
    else:
        update(a-1, b - arr[a-1])
