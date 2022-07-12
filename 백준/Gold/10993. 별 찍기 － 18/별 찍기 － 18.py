def star(n, x, y):
    if n == 1:
        map[y][x] = 1
        return map
    # 삼각형
    if n % 2 == 1: 
        star(1, x + x_size[n-1] // 2, y)
        for i in range(1, y_size[n-1] - 1):
            star(1, x + y_size[n-1] - i - 1, y + i)
            star(1, x + x_size[n-1] // 2 + i, y + i)
        for i in range(x_size[n-1]):
            star(1, x + i, y + y_size[n-1] - 1)
        star(n - 1, x + (x_size[n-1] - 1) // 2 // 2 + 1, y + y_size[n-1] // 2)
    # 역삼각형
    else:
        star(1, x + x_size[n-1] // 2, y + y_size[n-1] - 1)
        for i in range(1, y_size[n-1] - 1):
            star(1, x + i, y + i)
            star(1, x + y_size[n-1] - i + x_size[n-1] // 2 - 1, y + i)
        for i in range(x_size[n-1]):
            star(1, x + i, y)
        star(n - 1, x + x_size[n-1] // 2 // 2 + 1, y + 1)
n = int(input())

x_size = [1] * n
y_size = [1] * n
for i in range(1, n):
    x_size[i] = x_size[i-1] * 2 + 3
    y_size[i] = y_size[i-1] * 2 + 1
map = [[0] * x_size[n-1] for _ in range(y_size[n-1])]

star(n, 0, 0)

for y in range(y_size[n-1]):
    for x in range(x_size[n-1]):
        if n % 2 == 1:
            if x > (x_size[n-1] // 2 + y):
                continue
        else:
            if x > (y_size[n-1] - y + x_size[n-1] // 2 - 1):
                continue
        if map[y][x]:
            print('*', end='')
        else:
            print(' ', end='')
    print()