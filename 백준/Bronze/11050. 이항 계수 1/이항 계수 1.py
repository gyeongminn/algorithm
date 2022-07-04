from math import factorial

n, k = map(int, input().split())

num1 = 1
for i in range(k):
    num1 *= n - i

num2 = factorial(k)

print(num1 // num2)