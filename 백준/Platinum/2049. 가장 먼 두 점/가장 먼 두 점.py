import sys
input = sys.stdin.readline


def remove_middle(a, b, c):
    cross = (a[0] - b[0]) * (c[1] - b[1]) - (a[1] - b[1]) * (c[0] - b[0])
    dot = (a[0] - b[0]) * (c[0] - b[0]) + (a[1] - b[1]) * (c[1] - b[1])
    return cross < 0 or cross == 0 and dot <= 0


def convex_hull(points):
    spoints = sorted(points)
    hull = []
    for p in spoints + spoints[::-1]:
        while len(hull) > 2 and remove_middle(hull[-2], hull[-1], p):
            hull.pop()
        hull.append(p)
    hull.pop()
    return hull[::-1]


def sub_point(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    return [x1 - x2, y1 - y2]


def dist_square(p1, p2):
    dx, dy = sub_point(p1, p2)
    return dx * dx + dy * dy


def ccw(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    return x1 * y2 - x2 * y1


def rotating_calipers(hull):
    p1, p2 = 0, 1
    size = len(hull)
    max_dist = dist_square(hull[p1], hull[p2])
    for _ in range(size * 2):
        try:
            next_p1 = (p1 + 1) % size
            next_p2 = (p2 + 1) % size
            angle = ccw(sub_point(hull[next_p1], hull[p1]),
                        sub_point(hull[next_p2], hull[p2]))
            if angle > 0:
                p2 = next_p2
            elif angle < 0:
                p1 = next_p1
            else:
                p1, p2 = next_p1, next_p2
            max_dist = max(max_dist, dist_square(hull[p1], hull[p2]))
        except:
            pass
    return max_dist


def naive(points):
    max_dist = 0
    for p1 in points:
        for p2 in points:
            max_dist = max(max_dist, dist_square(p1, p2))
    return max_dist


n = int(input())
points = [[int(x) for x in input().rstrip().split()] for _ in range(n)]
if n < 1000:
    print(naive(points))
else:
    hull = convex_hull(points)
    print(rotating_calipers(hull))
