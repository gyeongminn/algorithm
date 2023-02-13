from math import ceil, log2
import sys


def mul(start, end, left, right, node):
    if right < start or left > end:
        return 1

    if left <= start and right >= end:
        return tree[node]

    mid = (start + end) // 2
    return mul(start, mid, left, right, node*2) * mul(mid+1, end, left, right, node*2+1) % mod


def update(start, end, node, index, value):
    if index < start or index > end:
        return

    if start == end:
        tree[node] = value
        return

    mid = (start + end) // 2
    update(start, mid, node*2, index, value)
    update(mid+1, end, node*2+1, index, value)
    tree[node] = tree[node*2] * tree[node*2+1] % mod


input = sys.stdin.readline
mod = 1000000007

n, m, k = map(int, input().split())

size = 2 ** ceil(log2(n))
tree = [0] * (size * 2)

for i in range(n):
    tree[size + i] = int(input())
for i in range(size-1, 0, -1):
    tree[i] = tree[i*2] * tree[i*2+1] % mod

for _ in range(m + k):
    a, b, c = map(int, input().split())
    if a == 1:
        update(1, size-1, 1, b, c)
    elif a == 2:
        print(int(mul(1, size, b, c, 1)))
