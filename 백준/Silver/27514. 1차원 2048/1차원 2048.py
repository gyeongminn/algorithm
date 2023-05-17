from math import log2
import sys
input = sys.stdin.readline

n = int(input())
d = [0] * 100
for x in input().split():
    if x != '0':
        k = int(log2(int(x)))
        d[k] += 1
        
for i in range(63):
    d[i+1] += d[i] // 2

for i in range(62, -1, -1):
    if d[i] > 0:
        print(2**i)
        break