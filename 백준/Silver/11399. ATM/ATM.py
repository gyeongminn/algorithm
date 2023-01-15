n = int(input())
time = list(map(int, input().split()))
sum = 0
time = sorted(time)
for i in range(n) :
    for j in range(0, i + 1) :
        sum += time[j]
print(sum)