n = int(input())

a = 0
b = c = 1

if n == 0:
    print(0)
elif n < 3:
    print(1)
else:
    for _ in range(2, n):
        a = b
        b = c
        c = a + b
    print(c)