n, m = map(int, input().split())
a = []
b = []
for i in range(m):
    x, y = map(int, input().split())
    if x < y:
        a.append(i + 1)
    else:
        b.append(i + 1)
if len(a) > len(b):
    a, b = b, a
print(len(a))
print(*a)
