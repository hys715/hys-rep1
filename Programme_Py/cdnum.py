a, b = map(int, input().split())
ans = 1
while b:
    a, b = b, a % b
prime = [0 for i in range(a + 1)]
p = []
for i in range(2, a + 1):
    if prime[i] == 0:
        p.append(i)
        for j in range(i, a + 1, i):
            prime[j] = 1
while a != 1:
    for i in p:
        t = 1
        while a % i == 0:
            t += 1
            a //= i
        ans *= t
print(ans)
