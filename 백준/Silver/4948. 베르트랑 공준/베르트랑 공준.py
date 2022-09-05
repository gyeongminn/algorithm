def solution(n):
    cnt = 0
    for i in range(n+1, 2*n+1):
        flag = True
        for j in range(2, int(i**0.5+1)):
            if i % j == 0:
                flag = False
                break
        if flag == True:
            cnt += 1
    return cnt

while True:
    n = int(input())
    if n == 0:
        break
    print(solution(n))