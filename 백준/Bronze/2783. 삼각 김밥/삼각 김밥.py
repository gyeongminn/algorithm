X, Y = map(int, input().split())
N = int(input())

answer = X * 1000 / Y

for _ in range(N):
    X, Y = map(int, input().split())
    answer = min(answer, X * 1000 / Y)

print(f"{answer:.2f}")