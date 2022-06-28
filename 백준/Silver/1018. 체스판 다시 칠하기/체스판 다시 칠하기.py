n, m = map(int, input().split())

chess = []

for _ in range(n) :
    chess.append(input())

min = 100

for ys in range(len(chess) - 8 + 1) :
    for xs in range(len(chess[0]) - 8 + 1) :
        Bcase = Wcase = 0
        for y in range(8) :
            for x in range(8) :
                if (x % 2 == 0 and y % 2 == 0) or (x % 2 == 1 and y % 2 == 1) :
                    if chess[y + ys][x + xs] != 'B' :
                        Bcase += 1
                    else :
                        Wcase += 1
                elif (x % 2 == 1 and y % 2 == 0) or (x % 2 == 0 and y % 2 == 1) :
                    if chess[y + ys][x + xs] != 'W' :
                        Bcase += 1
                    else :
                        Wcase += 1
        if min > Bcase :
            min = Bcase
        if min > Wcase :
            min = Wcase
                    
print(min)