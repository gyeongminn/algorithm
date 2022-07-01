def isGroupWord(arr):
    for i in range(len(arr)):
        flag = True
        for j in range(i + 1, len(arr)):
            if arr[i] != arr[j]:
                if flag:
                    flag = False
            if flag == False:
                if arr[i] == arr[j]:
                    return 0
    return 1

n = int(input())

answer = 0
for _ in range(n):
    answer += isGroupWord(list(input()))
print(answer)