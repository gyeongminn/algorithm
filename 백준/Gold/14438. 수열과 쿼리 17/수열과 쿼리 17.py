import sys
from math import ceil, log2

input = sys.stdin.readline
INF = sys.maxsize
UPDATE = 1
FIND_MIN = 2


def update(node, start, end, index, diff) :
    if index < start or end < index:
        return
    if start == end:
        seg_tree[node] = diff
        return
    mid = (start + end) // 2
    update(node*2, start, mid, index, diff)
    update(node*2+1, mid+1, end, index, diff)
    seg_tree[node] = min(seg_tree[node*2], seg_tree[node*2+1])


def find_min(start, end, left, right, node):
    if right < start or left > end:
        return INF

    if left <= start and right >= end:
        return seg_tree[node]

    mid = (start + end) // 2
    return min(find_min(start, mid, left, right, node*2), find_min(mid+1, end, left, right, node*2+1))


n = int(input())
arr = [int(x) for x in input().split()]

size = 2 ** ceil(log2(n))
seg_tree = [0] * (size * 2)

for i in range(n):
    seg_tree[size+i] = arr[i]
for i in range(size-1, 0, -1):
    seg_tree[i] = min(seg_tree[i*2], seg_tree[i*2+1])

m = int(input())
for _ in range(m):
    option, a, b = map(int, input().split())
    if option == UPDATE:
        arr[a-1] = b
        update(1, 1, size, a, b)
    elif option == FIND_MIN:
        print(find_min(1, size, a, b, 1))
