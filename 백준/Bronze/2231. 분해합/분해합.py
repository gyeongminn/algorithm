def answer(n):
    for i in range(1, n):
        arr = [int(a) for a in str(i)]
        s = i + sum(arr)
        if s == n:
            return i
    return 0

n = int(input())
print(answer(n))