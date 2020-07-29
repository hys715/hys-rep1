def sumsqr(n):
    return n * (n + 1) * (2 * n + 1) // 6


def F(n):
    ans = 0
    m = int(n**0.5)
    for i in range(1, m + 1):
        ans += i**2 * (n // i)
        ans += sumsqr(n // i) - sumsqr(m)
    return ans


n = 6
print(F(n))
