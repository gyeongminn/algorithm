n = int(input())
if n == 1:
    print(1)
else:
    i = 1
    r = 1
    while True:
        r += 6 * i
        i += 1
        if r >= n:
            break
    print(i)