import sys
input = sys.stdin.readline

n, m = map(int, input().split())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
print(*sorted(a+b))