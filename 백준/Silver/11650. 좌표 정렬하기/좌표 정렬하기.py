n = int(input())
coord = [[0, 0] for _ in range(n)]

for i in range(n):
    x, y = map(int, input().split())
    coord[i][0] = x
    coord[i][1] = y

coord = sorted(coord)
for i in range(n):
    print(coord[i][0], coord[i][1])