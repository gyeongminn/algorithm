import sys
input = sys.stdin.readline


def init(node, start, end):
    if start == end:
        tree[node] = arr[start]
        return

    mid = (start + end) // 2
    init(node*2, start, mid)
    init(node*2+1, mid+1, end)


def update(node, start, end, left, right, value):
    if left > end or right < start:
        return

    if left <= start and end <= right:
        tree[node] += value
        return

    mid = (start + end) // 2
    update(node*2, start, mid, left, right, value)
    update(node*2+1, mid+1, end, left, right, value)


def query(node, start, end, index, value):
    if end < index or index < start:
        return 0

    value += tree[node]

    if start == end:
        return value

    mid = (start + end) // 2
    left_value = query(node*2, start, mid, index, value)
    right_value = query(node*2+1, mid+1,  end, index, value)

    return left_value + right_value


n = int(input())
arr = [int(x) for x in input().split()]
m = int(input())
query_arr = [[int(x) for x in input().split()] for _ in range(m)]

tree = [0] * (n * 4)
init(1, 0, n-1)

for item in query_arr:
    if item[0] == 1:
        i, j, k = item[1:4]
        update(1, 0, n-1, i-1, j-1, k)

    elif item[0] == 2:
        x = item[1]
        print(query(1, 0, n-1, x-1, 0))
