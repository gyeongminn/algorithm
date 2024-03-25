N, M, L = map(int, input().split())

count = [0] * N
cur, answer = 0, -1

while max(count) < M:
    count[cur] += 1
    answer += 1
    if count[cur] & 1:
        cur = (cur + L) % N
    else:
        cur = (cur - L) % N

print(answer)
