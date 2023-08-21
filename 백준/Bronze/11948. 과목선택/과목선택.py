a = [int(input()) for _ in range(6)]
print(sum(a[:4])-min(a[:4]) + max(a[4:]))