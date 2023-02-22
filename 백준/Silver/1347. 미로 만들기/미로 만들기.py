import sys

input = sys.stdin.readline
dx = [0, -1, 0, 1]
dy = [1, 0, -1, 0]

_, note = input(), input()
dir, x, y, row_range, col_range = 0, 100, 100, [100, 100], [100, 100]
maze = [['#'] * 200 for _ in range(200)]
maze[100][100] = '.'
for opt in note:
    if opt == 'F':
        x, y = x + dx[dir], y + dy[dir]
        maze[y][x] = '.'
        if dir % 2 == 0:
            if y < 100:
                row_range[0] = min(row_range[0], y)
            else:
                row_range[1] = max(row_range[1], y)
        else:
            if x < 100:
                col_range[0] = min(col_range[0], x)
            else:
                col_range[1] = max(col_range[1], x)

    else:
        if opt == 'R':
            dir = (dir + 1) % 4
        if opt == 'L':
            dir = (dir + 3) % 4
maze = map(lambda x: x[col_range[0]:col_range[1]+1],
           maze[row_range[0]:row_range[1]+1])

for row in maze:
    print(*row, sep='')
