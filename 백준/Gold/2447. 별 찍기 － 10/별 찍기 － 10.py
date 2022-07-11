def star(n, x, y):
    if n == 3:
        for i in range(3):
            for j in range(3):
                if i != 1 or j != 1:
                    map[y + i][x + j] = 1
        return map
    
    n //= 3
    for i in range(3):
        for j in range(3):
            if i != 1 or j != 1:
                star(n, i * n + x, j * n + y)
                
n = int(input())
map = [[0] * n for _ in range(n)]

star(n, 0, 0)

for y in range(n):
    for x in range(n):
        if map[y][x]:
            print('*', end='')
        else:
            print(' ', end='')
    print()