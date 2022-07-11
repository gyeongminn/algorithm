t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))
    
    cnt = 1
    while True:
        if max(arr) != arr[0]:
            arr.append(arr.pop(0))
            m -= 1
            if m < 0:
                m = n - 1
        else:
            if m == 0:
                break
            arr.pop(0)
            cnt += 1
            m -= 1
            n -= 1
            if m < 0:
                m = n - 1
    print(cnt)