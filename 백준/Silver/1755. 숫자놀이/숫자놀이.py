dic = {
    1: 'one',
    2: 'two',
    3: 'three',
    4: 'four',
    5: 'five',
    6: 'six',
    7: 'seven',
    8: 'eight',
    9: 'nine',
    0: 'zero'
}

def change(x):
    if x < 10:
        return dic[x]
    return dic[x//10] + dic[x%10]

x, y = map(int, input().split())
arr = [int(x) for x in range(x, y+1)]

for i in range(len(arr)):
    for j in range(len(arr)):
        if change(arr[i]) < change(arr[j]):
            arr[i], arr[j] = arr[j], arr[i]

for i in range(len(arr)):
    if i != 0 and i % 10 == 0:
        print()
    print(arr[i], end=' ')
