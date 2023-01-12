s = input()

set_arr = set()
for i in range(len(s)):
    for j in range(i, len(s)):
        set_arr.add(s[i:j+1])

print(len(set_arr))
