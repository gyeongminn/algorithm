import sys

input = sys.stdin.readline

n, m = map(int, input().split())
arr = list(map(lambda x: x+1, range(n)))
for _ in range(m):
    i, j, k = map(int, input().split())
    arr = arr[:i-1] + arr[k-1:j] + arr[i-1:k-1] + arr[j:]
print(*arr)
