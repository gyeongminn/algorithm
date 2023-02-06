import sys

input = sys.stdin.readline

n, m, r = map(int, input().split())
arr = [[int(x) for x in input().split()] for _ in range(n)]
options = [int(x) for x in input().split()]

for option in options:
    if option == 1:
        arr = arr[::-1]
    elif option == 2:
        arr = list(map(lambda x: x[::-1], arr))
    elif option == 3:
        arr = list(zip(*arr[::-1]))
        n, m = m, n
    elif option == 4:
        arr = list(map(list, zip(*arr)))[::-1]
        n, m = m, n
    else:
        n_2, m_2 = n//2, m//2
        arr1 = map(lambda x: x[:m_2], arr[:n-n_2])
        arr2 = map(lambda x: x[m_2:], arr[:n-n_2])
        arr3 = map(lambda x: x[:m-m_2], arr[n_2:])
        arr4 = map(lambda x: x[m_2:], arr[n_2:])
        if option == 5:
            arr = list(map(lambda x: x[0]+x[1], list(zip(arr3, arr1)) + list(zip(arr4, arr2))))
        elif option == 6:
            arr = list(map(lambda x: x[0]+x[1], list(zip(arr2, arr4)) + list(zip(arr1, arr3))))

for row in arr:
    print(*row)
