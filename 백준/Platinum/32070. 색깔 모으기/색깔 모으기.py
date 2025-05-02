n = int(input())
a = [0 for _ in range(n)]
b = [0 for _ in range(n)]
sex = 0
for i in range(n):
    a[i], b[i] = map(int, input().split())
    if a[i] != b[i]:
        sex += 1
if sex == 0:
    print(0)
else:
    print(sex + 1)
