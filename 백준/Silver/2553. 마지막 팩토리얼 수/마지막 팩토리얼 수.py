import sys
input = sys.stdin.readline

n = int(input())

fact = 1
for i in range(2, n+1):
    fact *= i
    
for item in reversed(list(str(fact))):
    if item != '0':
        print(item)
        break