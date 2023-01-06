import sys

def solution(scores):
    result = 0
    max_rank = [100001, 100001]
    for score in sorted(scores):
        if max_rank[1] > score[1]:
            max_rank = score
            result += 1
    return result

t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())
    scores = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    print(solution(scores))
