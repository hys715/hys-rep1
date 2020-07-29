def init_string(L):
    res = "#"
    for i in L:
        res += i
        res += "#"
    return res


def manacher(s):
    i = 1
    j = 0
    n = len(s)
    rad = [0] * n
    while i < n:
        while i - j - 1 > 0 and i + j + 1 < n and s[i - j - 1] == s[i + j + 1]:
            j += 1
        rad[i] = j
        k = 1
        while k <= rad[i] and rad[i] - k != rad[i - k]:
            rad[i + k] = min(rad[i] - k, rad[i - k])
            k += 1
        j = max(j - k, 0)
        i += k
    radius = sorted(rad)[-1]
    center = rad.index(radius)
    res = s[center - radius: center + radius + 1]
    return res.replace('#', '')


LL = init_string(L)
print manacher(LL)