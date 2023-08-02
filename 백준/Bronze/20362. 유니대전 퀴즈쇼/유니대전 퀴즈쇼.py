n, an = input().split()
n = int(n)
arr = []
aw = ''
cnt = 0
for _ in range(n):
    name, word = input().split()
    if name == an:
        aw = word
        break
    arr.append(word)
        
for item in arr:
    if item == aw:
        cnt += 1
        
print(cnt)