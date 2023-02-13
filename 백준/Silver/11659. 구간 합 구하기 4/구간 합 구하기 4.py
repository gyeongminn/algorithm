from math import ceil, log2
import sys

input = sys.stdin.readline


def sum(start, end, left, right, node):
    if right < start or left > end:
        return 0

    if left <= start and right >= end:
        return tree[node]

    mid = (start + end) // 2
    return sum(start, mid, left, right, node*2) + sum(mid+1, end, left, right, node*2+1)


n, m = map(int, input().split())
arr = [int(x) for x in input().split()]

size = 2 ** ceil(log2(n))
tree = [0] * (size * 2)

for i in range(n):
    tree[size+i] = arr[i]
for i in range(size-1, 0, -1):
    tree[i] = tree[i*2] + tree[i*2+1]

for _ in range(m):
    a, b = map(int, input().split())
    print(sum(1, size, a, b, 1))
