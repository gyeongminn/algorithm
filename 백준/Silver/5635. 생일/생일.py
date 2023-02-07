person = list(sorted([input().split() for _ in range(int(input()))], key=lambda x: (int(x[3]),int(x[2]),int(x[1]))))
print(*(person[i][0] for i in (-1, 0)), sep='\n')