n = int(input())
a = list(map(int, input().split()))

ones = 1
zeros = a[0]
b = [0 for _ in range(n)]
b[0] = 1

sibal = False
for i in range(1, n):
    if a[i] == zeros and zeros == ones:
        b[i] = 1
        ones += 1
        continue
    if a[i] == zeros:
        b[i] = 1
        ones += 1
    elif a[i] == ones:
        b[i] = 0
        zeros -= 1
    else:
        sibal = True
        break
if not sibal and b.count(0) == a[0] and b.count(1) == a[-1]:
    print(*b)
    exit(0)

ones = 1
zeros = a[0]
b = [0 for _ in range(n)]
b[0] = 1

sibal = False
for i in range(1, n):
    if a[i] == zeros and zeros == ones:
        b[i] = 0
        zeros -= 1
        continue
    if a[i] == zeros:
        b[i] = 1
        ones += 1
    elif a[i] == ones:
        b[i] = 0
        zeros -= 1
    else:
        sibal = True
        break
if not sibal and b.count(0) == a[0] and b.count(1) == a[-1]:
    print(*b)
    exit(0)
print(-1)
