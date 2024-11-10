n = int(input())
a = []
for _ in range(n):
    p = list(map(int, input().split()))
    a.append(p)
res = 1e25
for i in range(n):
    for j in range(i + 1, n):
        lst = []
        for k in range(n):
            if k != i and k != j:
                lst.append(a[k])
        lst = sorted(lst)
        x = lst[-1][0] - lst[0][0]
        lst = sorted(lst, key=lambda x: x[1])
        y = lst[-1][1] - lst[0][1]
        res = min(res, (max(x, y) + 2) ** 2)
print(res)
