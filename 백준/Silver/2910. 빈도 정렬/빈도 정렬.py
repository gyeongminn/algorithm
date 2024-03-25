from collections import defaultdict

N, C = map(int, input().split())
dic = defaultdict(int)

for i in map(int, input().split()):
    dic[i] += 1

for i in sorted(dic, key=lambda x: -dic[x]):
    print(f'{i} ' * (dic[i]), end='')
