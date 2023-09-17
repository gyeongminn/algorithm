n, u, l = map(int, input().split())
boj = n >= 1000
maple = u >= 8000 or l >= 260

if boj and maple:
    print('Very Good')
elif boj:
    print('Good')
else:
    print('Bad')