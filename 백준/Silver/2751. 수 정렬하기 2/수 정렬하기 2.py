import sys
import random

input = sys.stdin.readline

arr = [int(input()) for _ in range(int(input()))]
random.shuffle(arr)
print(*sorted(arr), sep='\n')
