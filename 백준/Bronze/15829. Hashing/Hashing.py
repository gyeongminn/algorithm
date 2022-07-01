n = int(input())
arr = list(input())

sum = 0
for i in range(n):
    sum += (ord(arr[i]) - 96) * (31 ** i)
sum %= 1234567891

print(sum)