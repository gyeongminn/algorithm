import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
find = int(input())

print(arr.count(find))