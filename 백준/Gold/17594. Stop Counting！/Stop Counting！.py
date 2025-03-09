n = int(input())
a = [0, *list(map(int, input().split()))]
res = 0
psum = 0
for i in range(1, n + 1):
    psum += a[i]
    res = max(res, psum / i)
psum = 0
for i in range(1, n + 1)[::-1]:
    psum += a[i]
    res = max(res, psum / (n + 1 - i))
print(f"{res:.9f}")
