n, m = map(int, input().split())
for i in range(m):
    a = list(map(int, input().split()))
    for j in range(1, n + 1):
        b = [-1] * j + [1] * (n - j)
        cur = 0
        for x in range(n):
            cur += a[x] * b[x]
        if cur == 0:
            print(" ".join(map(str, b)))
            break
