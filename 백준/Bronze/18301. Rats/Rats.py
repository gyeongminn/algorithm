from math import *
import sys
input = sys.stdin.readline

a, b, c = map(int, input().split())

print(floor((a+1) * (b+1) / (c+1) - 1))