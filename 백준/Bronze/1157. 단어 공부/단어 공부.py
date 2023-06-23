s = list(input())

dic = {}
for c in s:
    dic[c.upper()] = 0
for c in s:
    dic[c.upper()] += 1
    
s = sorted(dic.items(), key=lambda x: x[1], reverse=True)
if len(s) == 1:
    print(s[0][0])
else:
    if s[0][1] == s[1][1]:
        print('?')
    else:
        print(s[0][0])
