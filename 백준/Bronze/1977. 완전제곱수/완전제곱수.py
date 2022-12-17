n = int(input())
m = int(input())

a = [i*i for i in range(1, 101) if n <= i*i <= m]

if len(a) == 0:
    print(-1)
else:
    print(sum(a))
    print(a[0])
