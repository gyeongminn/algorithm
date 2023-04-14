import bisect
import sys
input = sys.stdin.readline

str = input().rstrip()
arr = [[] for _ in range(26)]
for i, c in enumerate(str):
    idx = ord(c) - 97
    arr[idx].append(i)

q = int(input())
for _ in range(q):
    a, l, r = input().rstrip().split()
    idx = ord(a) - 97
    left = bisect.bisect_left(arr[idx], int(l))
    right = bisect.bisect_right(arr[idx], int(r))
    print(right - left)
