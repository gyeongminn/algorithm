def go(r, c, d):
    if arr[r+dir[d][0]][c+dir[d][1]] == 1:
        return r, c, True
    r += dir[d][0]
    c += dir[d][1]
    return r, c, False


def is_space(r, c, d):
    r, c, is_wall = go(r, c, d)
    if r < 0 or r >= nrow:
        return False
    elif c < 0 or c >= ncol:
        return False
    elif is_wall:
        return False
    elif arr[r][c] == 0:
        return True


nrow, ncol = map(int, input().split())
r, c, d = map(int, input().split())
arr = []

dir = [[-1, 0], [0, 1], [1, 0], [0, -1]]

for _ in range(nrow):
    arr.append(list(map(int, input().split())))

passing = False
result = 0
count = 0

while True:
    # 2-3
    if count == 4:
        count = 0
        passing = True
        r, c, is_wall = go(r, c, (d + 2) % 4)
        if is_wall:  # 2-4
            break

    # 1
    if passing == False and arr[r][c] == 0:
        arr[r][c] = 2
        result += 1
        count = 0

    # 2-1
    passing = False
    if is_space(r, c, (d + 3) % 4):
        d = (d + 3) % 4
        r, c, is_wall = go(r, c, d)
        count = 0
        continue

    # 2-2
    else:
        count += 1
        passing = True
        d = (d + 3) % 4

print(result)
