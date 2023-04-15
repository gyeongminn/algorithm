import sys
input = sys.stdin.readline


def ccw(p1, p2, p3):
    return (p2[0] - p1[0]) * (p3[1] - p1[1]) - (p2[1] - p1[1]) * (p3[0] - p1[0])


def convex_hull(points):
    points = sorted(points)
    lower = []
    for p in points:
        while len(lower) >= 2 and ccw(lower[-2], lower[-1], p) < 0:
            lower.pop()
        lower.append(p)
    upper = []
    for p in reversed(points):
        while len(upper) >= 2 and ccw(upper[-2], upper[-1], p) < 0:
            upper.pop()
        upper.append(p)
    return lower[:-1] + upper[:-1]


points = []
cnt = 0
n = int(input())
for _ in range(n):
    x, y, c = input().split()
    x, y = map(int, [x, y])
    if c == 'Y':
        cnt += 1
    points.append((x, y))
    
print(cnt)
for x, y in (convex_hull(points)):
    print(x, y)
