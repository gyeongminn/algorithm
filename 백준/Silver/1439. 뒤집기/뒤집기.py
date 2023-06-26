s = input().rstrip()
c0, c1 = 0, 0
for i in range(len(s)-1):
    if s[i] == '0' and s[i+1] != s[i]:
        c0 += 1
    elif s[i] == '1' and s[i+1] != s[i]:
        c1 += 1
print(max(c0, c1))