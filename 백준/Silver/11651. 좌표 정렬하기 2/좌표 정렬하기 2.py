n = int(input())
coord = [[0, 0] for _ in range(n)]

for i in range(n):
    x, y = map(int, input().split())
    coord[i][0] = y
    coord[i][1] = x

coord = sorted(coord)
for i in range(n):
    print(coord[i][1], coord[i][0])