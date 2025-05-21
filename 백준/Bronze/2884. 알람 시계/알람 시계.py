h1, m2 = input().split()

h1 = int(h1)
m1 = int(m2)

m2 = m1 - 45

if m2 < 0 :
    h2 = h1 - 1
    m2 = 60 + m2

    if h2 == -1 :
        h2 = 23

else :
    h2 = h1
    m2 = m2

print(h2, m2)