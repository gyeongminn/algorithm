import sys

input = sys.stdin.readline

k, n = map(int, input().split())
arr = [int(input()) for _ in range(k)]

start, end = 1, max(arr)
while start <= end:
    mid = (start + end) // 2
    cable = sum(map(lambda x: x//mid, arr))
    if cable >= n:
        start = mid + 1
    else:
        end = mid - 1
        
print(end)
    