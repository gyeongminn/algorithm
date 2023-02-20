def han(num):
    arr = list(map(int, str(num)))
    for i in range(1, len(arr) - 1):
        if arr[i-1] - arr[i] != arr[i] - arr[i+1]:
            return False
    return True

n = int(input())
cnt = 0
for i in range(n):
    if han(i + 1):
        cnt += 1
print(cnt)