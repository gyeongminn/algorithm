from itertools import combinations
import sys
input = sys.stdin.readline

n = int(input())
arr = [int(x) for x in input().split()]
s = sum(arr)

res = [False] * s
for i in arr:
    res[i-1] = True

for i in range(n+1):
    for left in list(combinations(arr, i)):
        tmp = [x for x in arr if x not in left]
        sum_left = sum(left)
        for j in range(len(tmp)+1):
            for right in list(combinations(tmp, j)):
                sum_right = sum(right)
                idx = sum_left - sum_right - 1
                if 0 <= idx < s and (left or right):
                    res[idx] = True

print(res.count(False))
