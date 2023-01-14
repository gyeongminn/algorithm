from math import ceil, log2
import sys


def sum(start, end, left, right, node):
    if right < start or left > end:
        return 0

    if left <= start and right >= end:
        return tree[node]

    mid = (start + end) // 2
    return sum(start, mid, left, right, node*2) + sum(mid+1, end, left, right, node*2+1)


def update(index, add):
    node = index + size - 1
    while node >= 1:
        tree[node] += add
        node //= 2


input = sys.stdin.readline

n, m, k = map(int, input().split())

size = 2 ** ceil(log2(n))
tree = [0] * (size * 2)

for i in range(n):
    tree[size + i] = int(input())
for i in range(size-1, 0, -1):
    tree[i] = tree[i*2] + tree[i*2+1]

for _ in range(m + k):
    a, b, c = map(int, input().split())
    if a == 1:
        update(b, c-tree[size+b-1])
    elif a == 2:
        print(sum(1, size, b, c, 1))
