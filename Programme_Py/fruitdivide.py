L = [1, 3, 6]
ans = sum(L)    # sum of weight
lth = len(L)    # len of list
f = [[0] for i in range(ans + 1)]
f[0][0] = 1
f[0].append(0)
flag = 0    # judge whether the solution exists
for j in range(lth):
    for i in range(ans, L[j] - 1, -1):
        # if the combination whose weight is (i - L[j]) exists
        if f[i - L[j]][0]:
            for k in range(1, f[i - L[j]][0] + 1):
                # store the combination in binary form
                f[i].append(f[i - L[j]][k] | (1 << j))
            f[i][0] += f[i - L[j]][0]   # add the number
for i in range(ans, 1, -1):
    # if f[i][0] and f[i // 2][0] exist
    if i % 2 == 0 and f[i][0] and f[i // 2][0]:
        for j in range(1, f[i][0] + 1):
            for k in range(1, f[i // 2][0] + 1):
                # if f[i // 2][k] is subset of f[i][j]
                if f[i][j] & f[i // 2][k] == f[i // 2][k]:
                    flag = 1    # find the solution
                    print(i // 2)
                    break
            if flag:
                break
        if flag:
            break
if not flag:
    print(0)
