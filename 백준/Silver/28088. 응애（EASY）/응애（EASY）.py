n, m, k = map(int, input().split())
a = [0 for _ in range(n)]
for i in range(m):
    x = int(input())
    a[x] = 1
for i in range(k):
    b = [0 for _ in range(n)]
    for j in range(n):
        if a[(j - 1 + n) % n] ^ a[(j + 1) % n] == 1:
            b[j] = 1
    a = b
print(sum(a))
