import sys
input = sys.stdin.readline


n = int(input())
arr = [int(x) for x in input().split()]
m = int(input())

start, end = 1, max(arr)

while start <= end:
    mid = (start + end) // 2
    sum_money = 0
    for i in arr:
        if i < mid:
            sum_money += i
        else:
            sum_money += mid
    if sum_money <= m:
        start = mid + 1
    else:
        end = mid - 1
        
print(end)
