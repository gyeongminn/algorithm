from math import *

d, hr, hw = map(int, input().split())
a = d / sqrt(hr * hr + hw * hw)

print(floor(hr * a), floor(hw * a))
