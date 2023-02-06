import math


def is_palindrome(n: int):
    return str(n) == str(n)[::-1]


a, b = map(int, input().split())
if b >= 10000000: b = 10000000
numbers = [True if x % 2 == 1 else False for x in range(b + 1)]

for i in range(2, int(math.sqrt(b)) + 1):
    if numbers[i] == True:
        j = 2
        while i * j <= b:
            numbers[i * j] = False
            j += 1

for i in range(a, b + 1):
    if i % 2 == 0: continue
    if numbers[i] and is_palindrome(i):
        print(i)
print(-1)
