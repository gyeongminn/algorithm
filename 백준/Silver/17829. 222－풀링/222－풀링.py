import math
import sys
input = sys.stdin.readline

n = int(input())
arr = [[int(x) for x in input().split()] for _ in range(n)]

for k in range(math.ceil(math.log2(n))-1, -1, -1):
    tmp = [[0] * 2**k for _ in range(2**k)]
    for j in range(0, len(arr), 2):
        for i in range(0, len(arr), 2):
            val = sorted([arr[j][i], arr[j+1][i], arr[j]
                         [i+1], arr[j+1][i+1]])[-2]
            tmp[i//2][j//2] = val
    arr = tmp
    
print(arr[0][0])
