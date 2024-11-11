n = int(input())
k = int(input())
for _ in range(k):
    x, y = map(int, input().split())
    if x > (n + 1) // 2:
        x = n - x + 1
    if y > (n + 1) // 2:
        y = n - y + 1
    if y <= x and x <= n - y:
        print(y % 3 if y % 3 else 3)
    else:
        print(x % 3 if x % 3 else 3)
