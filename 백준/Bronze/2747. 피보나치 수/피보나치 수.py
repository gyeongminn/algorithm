n = int(input())

fib = [1, 1, 2]
if n < 0:
    pass
elif n < 4:
    print(fib[n-1])
else:
    for i in range(3, n):
        fib.append(fib[i-1] + fib[i-2])
    print(fib[i])