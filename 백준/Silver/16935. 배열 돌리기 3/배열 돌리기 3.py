import sys

input = sys.stdin.readline

n, m, r = map(int, input().split())
arr = [[int(x) for x in input().split()] for _ in range(n)]
options = [int(x) for x in input().split()]

for option in options:
    if option == 1:
        arr = arr[::-1]  # 상하 반전
    elif option == 2:
        arr = list(map(lambda x: x[::-1], arr))  # 좌우 반전
    elif option == 3:
        arr = list(zip(*arr[::-1]))  # 오른쪽으로 90도 회전
        n, m = m, n  # 행, 열 사이즈 스왑
    elif option == 4:
        arr = list(map(list, zip(*arr)))[::-1]  # 왼쪽으로 90도 회전
        n, m = m, n
    else:
        arr1 = map(lambda x: x[:m//2], arr[:n//2])  # 1사분면
        arr2 = map(lambda x: x[m//2:], arr[:n//2])  # 2사분면
        arr3 = map(lambda x: x[:m//2], arr[n//2:])  # 3사분면
        arr4 = map(lambda x: x[m//2:], arr[n//2:])  # 4사분면
        if option == 5:  # 시계 방향 사분면 회전
            arr = list(zip(arr3, arr1)) + list(zip(arr4, arr2))
        elif option == 6:  # 반시계 방향 사분면 회전
            arr = list(zip(arr2, arr4)) + list(zip(arr1, arr3))
        arr = list(map(lambda x: x[0]+x[1], arr))

for row in arr:
    print(*row)
