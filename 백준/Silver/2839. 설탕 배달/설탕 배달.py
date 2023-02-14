n = int(input())
x = 0
while True:
    if n % 5 == 0:
        x += n // 5
        break
    elif n == 0:
        break
    elif n < 0:
        x = -1
        break
    else:
        x += 1
        n -= 3
print(x)
