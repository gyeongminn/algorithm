import sys

input = sys.stdin.readline

a = input().rstrip()
if (a == a[::-1]):
    print(1)
else:
    print(0)
