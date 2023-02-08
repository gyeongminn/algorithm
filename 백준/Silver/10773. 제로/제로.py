k = int(input())
q = []

for _ in range(k):
    n = int(input())
    if n == 0:
        del q[-1]
    else:
        q.append(n)
        
print(sum(q))