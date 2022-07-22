c = list(input())

for i in range(26):
    for j in range(len(c)):
        z = ord(c[j]) - ord('a')
        if ord(c[j]) - ord('a') == i:
            print(j, end=' ')
            break
    else:
        print(-1, end=' ')
