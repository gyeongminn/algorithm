def solution(arr, n, k):
    count = 0
    while arr:
        p = arr.pop(0)
        count += 1
        if count == k:
            return p

        i = 1
        while i * p <= n:
            if p * i in arr:
                arr.remove(p * i)
                count += 1
                if count == k:
                    return p * i
            i += 1


n, k = map(int, input().split())
arr = [*range(2, n+1)]
print(solution(arr, n, k))
