from itertools import combinations

height = []
for _ in range(9):
    height.append(int(input()))

com_height = combinations(height, 7)

for s in com_height:
    if sum(s) == 100:
        for h in sorted(s):
            print(h)
        break