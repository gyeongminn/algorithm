dice = list(map(int, input().split()))

dice = sorted(dice)

if dice[0] == dice[1] == dice[2]:
    print(10000 + 1000 * dice[0])
    
elif dice[0] == dice[1]:
    print(1000 + 100 * dice[0])

elif dice[1] == dice[2]:
    print(1000 + 100 * dice[1])

else:
    print(100 * dice[2])
    