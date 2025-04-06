n = int(input())
a = []
for i in range(n):
    x, y = map(int, input().split())
    plus = min(x, y)
    minus = -max(x, y)
    a.append([x, y, plus - minus])
a.sort(key=lambda x: x[2])
ans = 0
for i in range(n):
    if i < n // 2:
        ans += min(a[i][0], a[i][1])
    else:
        ans -= max(a[i][0], a[i][1])
print(ans)
