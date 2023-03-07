import sys
from math import sqrt
input = sys.stdin.readline

t1 = [int(x) for x in input().split()]
t2 = [int(x) for x in input().split()]

d = sqrt(pow((abs(t1[0] - t2[0])), 2) + pow((abs(t1[1] - t2[1])), 2))
r = t1[2] + t2[2]

if d < r:
    print('YES')
else:
    print('NO')
