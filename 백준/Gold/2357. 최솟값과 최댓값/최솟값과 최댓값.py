from math import ceil, log2
import sys

input = sys.stdin.readline


def find_min(start, end, left, right, node):
    if right < start or left > end:
        return 1000000001

    if left <= start and right >= end:
        return min_tree[node]

    mid = (start + end) // 2
    return min(find_min(start, mid, left, right, node*2), find_min(mid+1, end, left, right, node*2+1))


def find_max(start, end, left, right, node):
    if right < start or left > end:
        return 0

    if left <= start and right >= end:
        return max_tree[node]

    mid = (start + end) // 2
    return max(find_max(start, mid, left, right, node*2), find_max(mid+1, end, left, right, node*2+1))


n, m = map(int, input().split())

size = 2 ** ceil(log2(n))
max_tree = [0] * (size * 2)
min_tree = [0] * (size * 2)

for i in range(n):
    num = int(input())
    max_tree[size + i] = num
    min_tree[size + i] = num

for i in range(size-1, 0, -1):
    min_tree[i] = min(min_tree[i*2], min_tree[i*2+1])
    max_tree[i] = max(max_tree[i*2], max_tree[i*2+1])

for _ in range(m):
    a, b = map(int, input().split())
    print(find_min(1, size, a, b, 1), find_max(1, size, a, b, 1))
