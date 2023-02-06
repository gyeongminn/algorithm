import sys

input = sys.stdin.readline


def count_range(start, end):
    count = 0
    for j in range(start, end+1):
        for k in range(j+1, end+1):
            if j <= n <= k:
                count += 1
    return count


l = int(input())
arr = sorted([int(x) for x in input().split()])
n = int(input())
result = 0

result += count_range(1, arr[0]-1)
for i in range(l-1):
    result += count_range(arr[i]+1, arr[i+1]-1)

print(result)
