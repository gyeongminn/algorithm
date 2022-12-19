def count_diffrents(a: list, b: list):  # 문자열의 차이를 계산
    count = 0
    for i in range(len(a)):  # 두 리스트의 길이는 같다고 가정
        if a[i] != b[i]:
            count += 1
    return count


def solution(a: list, b: list):  # 솔루션
    if len(a) == len(b):  # 길이가 같으면 바로 차이 리턴
        return count_diffrents(a, b)
    min_diff = 50  # 같은 부분이 많은 시작 인덱스
    for i in range(len(b) - len(a)+1):  # 슬라이싱 범위(0 ~ a와 b의 길이 차)
        cur_diff = count_diffrents(a, b[i:len(a)+i])  # 슬라이싱 후 차이 계산
        min_diff = min(min_diff, cur_diff)  # 최소값 계산
    return min_diff  # 최소 차이 리턴


a, b = map(list, input().split())
print(solution(a, b))
