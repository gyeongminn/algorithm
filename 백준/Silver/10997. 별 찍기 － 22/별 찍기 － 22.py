def star(n, x, y, x_size, y_size):
    if n == 1:
        for i in range(3):
            map[y + i][x] = '*'
        return map
    for i in range(2):
        for j in range(x_size):
            map[y + i * (y_size - 1)][x + j] = '*'
    for i in range(2):
        for j in range(y_size):
            map[y + j][x + i * (x_size - 1)] = '*'
    map[y + 1][x + x_size - 1] = ' '
    map[y + 2][x + x_size - 2] = '*'
    star(n - 1, x + 2, y + 2, x_size - 4, y_size - 4)
    
n = int(input())
if n == 1:
    print('*')
else:
    x_size = 4 * n - 3
    y_size = 4 * n - 1
    map = [[' '] * (x_size) for _ in range(y_size)]
    star(n, 0, 0, x_size, y_size)
    for y in range(y_size):
        for x in range(x_size):
            if y == 1 and x > 1:
                continue
            print(map[y][x], end='')
        print()