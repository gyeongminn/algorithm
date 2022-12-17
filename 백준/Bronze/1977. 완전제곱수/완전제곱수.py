n = int(input())
m = int(input())

square = [x**2 for x in range(1, 101)]

arr = []
for i in range(n, m+1):
    if i in square:
        arr.append(i)
        
if arr == []:
    print(-1)
else:
    print(sum(arr))
    print(arr[0])