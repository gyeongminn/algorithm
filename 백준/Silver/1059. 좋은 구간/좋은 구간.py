import sys

input = sys.stdin.readline

l = int(input())
arr = sorted([int(x) for x in input().split()])
n = int(input())
result = 0

start, end = 1, arr[0]-1
for j in range(start, end+1):
    for k in range(j+1, end+1):
        if j <= n <= k:
            result += 1

for i in range(l-1):
    start, end = arr[i]+1, arr[i+1]-1
    for j in range(start, end+1):
        for k in range(j+1, end+1):
            if j <= n <= k:
                result += 1
print(result)