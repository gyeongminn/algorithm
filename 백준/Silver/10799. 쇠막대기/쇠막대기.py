arr = list(input())

result = 0
n = 0

for i in range(len(arr)):
    if arr[i] == '(':
        n += 1
        
    else:
        n -= 1
        if arr[i-1] == '(':
            result += n
        else:
            result += 1

print(result)