def hanoi(n, From, To, Tmp):
    if n == 0 : return
    hanoi(n-1, From, Tmp, To)
    print(From, Tmp)
    hanoi(n-1, To, From, Tmp)

n = int(input())
print(2 ** n - 1)
if n <= 20:
    From = n
    To = Tmp = 0
    hanoi(n, 1, 2, 3)