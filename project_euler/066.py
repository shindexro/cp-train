import math


def chakravala(a, b, k, n):
    while k != 1:
        m = 0
        while (a + b * m) % k:
            m += 1

        m2 = m + abs(k)
        while abs(m2 ** 2 - n) < abs(m ** 2 - n):
            m = m2
            m2 += abs(k)

        a, b, k = (m * a + n * b) // abs(k), (a + m * b) // abs(k), (m ** 2 - n) // k

    return a, b, k


ans = (-1, -1)
for i in range(1, 10001):
    if i == int(math.sqrt(i)) ** 2:
        continue

    c = 7  # arbitrary
    x, y, k = chakravala(c, 1, c ** 2 - i, i)
    assert x ** 2 - i * y ** 2 == k

    if x > ans[1]:
        ans = (i, x)
        print(ans)

print(ans)
