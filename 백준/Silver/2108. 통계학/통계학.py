def mode(arr):
    # 배열의 개수 세기
    dic = {}
    for num in arr:
        if num in dic:
            dic[num] += 1
        else:
            dic[num] = 1

    max_count = max(dic.values())
    mode_arr = []
    for i in dic:
        if max_count == dic[i]:
            mode_arr.append(i)

    if len(mode_arr) == 1:
        return mode_arr[0]
    return mode_arr[1]


n = int(input())
arr = []
for _ in range(n):
    arr.append(int(input()))

print(round(sum(arr) / len(arr))) # 산술평균
print(sorted(arr)[n // 2]) # 중앙값
print(mode(arr)) # 최빈값
print(max(arr)-min(arr)) # 범위
