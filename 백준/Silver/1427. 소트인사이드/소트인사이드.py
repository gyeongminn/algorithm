arr = list(map(int, input()))
s = ''
for n in map(str, (sorted(arr, reverse=True))):
    s += n
print(s)
