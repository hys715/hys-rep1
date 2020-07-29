def conflict(state, next_x):
    next_y = len(state)
    for i in range(next_y):
        if abs(state[i] - next_x) in (0, next_y - i):
            return True
    return False


def queens(num=8, state=()):
    for i in range(num):
        if not conflict(state, i):
            if len(state) == num - 1:
                yield (i,)
            for result in queens(num, state + (i,)):
                yield (i,) + result


count = 0
for solution in queens(int(input())):
    count += 1
    if count < 4:
        for element in solution:
            print(element + 1, end=' ')
        print()
print(count)
