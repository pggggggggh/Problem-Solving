n = int(input())
a, b, c, d = map(int, input().split())
if a > b:
    a, b = b, a
if c > d:
    c, d = d, c
for i in range(1, n + 1):
    if i == b:
        print(i, 1)
    elif i == d:
        print(i, -1)
    else:
        if i == n:
            print(10**9, 10**9)
        else:
            print(i, 0)
