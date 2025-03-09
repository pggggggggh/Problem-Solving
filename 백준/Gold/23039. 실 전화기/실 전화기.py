n = int(input())
a = set()
for _ in range(n):
    x, y = map(int, input().split())
    if x > y:
        x, y = y, x
    a.add((x, y))
cross = 0
no = [[1, 4, 2, 5], [1, 4, 3, 5], [1, 3, 2, 5], [1, 3, 2, 4], [2, 4, 3, 5]]
for x, y, z, w in no:
    if (x, y) in a and (z, w) in a:
        cross += 1
if n == 10:
    print(-1)
elif cross == 0:
    print(0)
elif cross == 5:
    print(2)
else:
    print(1)
