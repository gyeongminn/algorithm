def star(n, x, y):
    if n == 3:
        map[y + 0][x + 2] = 1
        map[y + 1][x + 1] = map[y + 1][x + 3] = 1
        for i in range(5):
            map[y + 2][x + i] = 1
        return map
    
    n //= 2
    star(n, n + x, y)
    star(n, x, n + y)
    star(n, n * 2 + x, n + y)
                
n = int(input())
map = [[0] * n * 2 for _ in range(n)]

star(n, 0, 0)

for y in range(n):
    for x in range(n * 2):
        if map[y][x]:
            print('*', end='')
        else:
            print(' ', end='')
    print()