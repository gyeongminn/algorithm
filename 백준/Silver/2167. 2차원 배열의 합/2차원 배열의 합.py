import sys
input = sys.stdin.readline


def solution(arr, x1, y1, x2, y2):
    sum = 0
    for i in range(y1, y2+1):
        for j in range(x1, x2+1):
            sum += arr[j-1][i-1]
    return sum


n, m = map(int, input().split())
arr = [[int(x) for x in input().split()] for _ in range(n)]
k = int(input())

for _ in range(k):
    i, j, x, y = map(int, input().split())
    print(solution(arr, i, j, x, y))
