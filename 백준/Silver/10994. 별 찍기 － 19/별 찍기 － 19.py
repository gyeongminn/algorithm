def star(n, x, y):
    if n == 1:
        map[y][x] = '*'
        return map
    size = 4 * n - 3
    for i in range(2):
        for j in range(size):
            star(1, x + j, y + i * (size - 1))
    for i in range(size):
        for j in range(2):
            star(1, x + j * (size - 1), y + i)
    star(n - 1, x + 2, y + 2)
    
n = int(input())
size = 4 * n - 3
map = [[' '] * size for _ in range(size)]

star(n, 0, 0)

for y in range(size):
    for x in range(size):
        print(map[y][x], end='')
    print()