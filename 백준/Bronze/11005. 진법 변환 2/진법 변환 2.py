import sys
input = sys.stdin.readline

n, b = map(int, input().split())
stack = []
while n:
    c = n % b
    n //= b
    if c > 9:
        c = chr(c + 65 - 10)
    stack.append(c)

for _ in range(len(stack)):
    print(stack.pop(), end='')