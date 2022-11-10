import sys
n = int(input())
sum = 0
score = list(map(int,input().split()))
score.sort()
for i in range(n) :
    sum += score[i] / score[n-1] * 100
print(sum / n)