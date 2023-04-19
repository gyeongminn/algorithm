import sys
input = sys.stdin.readline
coin = [500, 100, 50, 10, 5, 1]

n = 1000 - int(input())
result = 0
for c in coin:
    result += n // c
    n %= c
print(result)