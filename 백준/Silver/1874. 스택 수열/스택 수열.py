def solution(n: int):
    cur = 0
    stack = []
    answer = []
    for _ in range(n):
        m = int(input())
        while cur < m:
            cur += 1
            answer.append("+")
            stack.append(cur)
        if stack[-1] == m:
            stack.pop()
            answer.append("-")
        else:
            answer = ["NO"]
            break
    return answer

n = int(input())
for s in solution(n):
    print(s)