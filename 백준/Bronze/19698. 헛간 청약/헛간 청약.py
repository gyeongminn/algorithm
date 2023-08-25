n, w, h, l = map(int, input().split())
ans = (w // l) * (h // l)
print(min(ans, n))
