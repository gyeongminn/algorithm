def factorial(K):
    if K < 2:
        return 1
    else:
        return K * factorial(K-1)

N, K = map(int, input().split())

num1 = 1
for i in range(K):
    num1 *= N-i

num2 = factorial(K)

print(num1 // num2)