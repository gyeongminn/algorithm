import sys

input = sys.stdin.readline

n = int(input())
start = 1
result = 0

if len(str(n)) > 2:
    start = int('9' * (len(str(n)) - 2))
    
for i in range(start, n):
    if n == i + sum(map(int, str(i))):
        result = i
        break
    
print(result)