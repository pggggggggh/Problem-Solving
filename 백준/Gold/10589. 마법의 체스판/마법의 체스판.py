n, m = map(int, input().split())
print(n // 2 + m // 2)
for i in range(2, m + 1, 2):
    print(1, i, n, i)
for i in range(2, n + 1, 2):
    print(i, 1, i, m)
