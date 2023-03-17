import decimal
import sys
decimal.getcontext().prec = 1000
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    sqrt3 = decimal.Decimal(1) / decimal.Decimal(3)
    n = round(decimal.Decimal(int(input()) ** sqrt3), 500)
    print(n.quantize(decimal.Decimal('.0000000001'), rounding=decimal.ROUND_DOWN))
