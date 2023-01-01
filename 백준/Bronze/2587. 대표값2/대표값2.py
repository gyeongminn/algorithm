arr = []

for _ in range(5):
    n = int(input())
    arr.append(n)

arr.sort()

print(int(sum(arr)/len(arr)))
print(arr[len(arr)//2])
