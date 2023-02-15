import sys

input = sys.stdin.readline


def solution(n):
    i = 1
    while True:
        d = int("1" * i)
        if d % n == 0:
            return i
        i += 1


while True:
    try:
        n = int(input())
        print(solution(n))
    except:
        break
