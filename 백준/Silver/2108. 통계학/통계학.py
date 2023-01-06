import sys
n = int(input())
l = []

for _ in range(n):
    l.append(int(sys.stdin.readline()))

l.sort()

print('%d'%(round(sum(l)/n, 0)))                            # 산술평균
print(l[n//2])                                              # 중앙값

x = {}                                                      # 딕셔너리 생성

for i in l:                                                 # 빈도수 저장
    if i in x:
        x[i] += 1
    else:
        x[i] = 1
x = sorted(x.items(), key=lambda x : x[1], reverse = True)  # 빈도수를 기준으로 오름차순 정렬

if n != 1: 
    if x[0][1] == x[1][1]:                                  # 최빈값이 여러 개 있다면 최빈값 중 두번째로 작은값 출력
        print(x[1][0])
    else: print(x[0][0])
else:
    print(x[0][0])

print(max(l) - min(l))                                      # 범위