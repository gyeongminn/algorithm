n, m = map(int, input().split())
staff = list(map(int, input().split()))

min_time = 0
start = 0
end = int(1e12)

while start <= end:
    mid = (start+end) // 2
    if sum(map(lambda x: mid//x, staff)) >= m:
        min_time = mid
        end = mid - 1
    else:
        start = mid + 1

print(min_time)
