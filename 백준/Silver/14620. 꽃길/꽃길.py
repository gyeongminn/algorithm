import sys
from itertools import combinations

input = sys.stdin.readline
int_max = int(2e9)


def is_dead(p1, p2):
    if abs(p1[0] - p2[0]) == 0:
        if abs(p1[1] - p2[1]) < 3:
            return True
    elif abs(p1[0] - p2[0]) == 1:
        if abs(p1[1] - p2[1]) < 2:
            return True
    elif abs(p1[0] - p2[0]) == 2:
        if abs(p1[1] - p2[1]) < 1:
            return True
    return False


def get_cost(p):
    x, y = p
    return cost[y][x] + cost[y-1][x] + cost[y+1][x] + cost[y][x-1] + cost[y][x+1]


def solution(p1, p2, p3):
    if is_dead(p1, p2) or is_dead(p2, p3) or is_dead(p3, p1):
        return int_max

    return get_cost(p1) + get_cost(p2) + get_cost(p3)


n = int(input())
cost = [[int(x) for x in input().split()] for _ in range(n)]
pos = [(x, y) for x in range(1, n-1) for y in range(1, n-1)]

result = int_max
for p1, p2, p3 in combinations(pos, 3):
    result = min(result, solution(p1, p2, p3))

print(result)