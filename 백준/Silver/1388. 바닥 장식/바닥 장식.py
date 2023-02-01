def solution(n, m):
    answer = n * m
    for y in range(n):
        for x in range(m):
            if wood[y][x] == '-':
                if x < m - 1 and wood[y][x+1] == '-':
                    answer -= 1
            elif wood[y][x] == '|':
                if y < n - 1 and wood[y+1][x] == '|':
                    answer -= 1
    return answer


n, m = map(int, input().split())
wood = [list(input()) for _ in range(n)]
print(solution(n, m))
