s = input()
for i in range(len(s)):
    tmp = s + s[:i][::-1]
    if (tmp == tmp[::-1]):
        print(len(s) + i)
        break