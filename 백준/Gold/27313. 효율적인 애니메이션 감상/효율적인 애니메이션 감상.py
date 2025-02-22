n, m, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
lo = 0
hi = n + 1
while lo + 1 < hi:
    mid = lo + hi >> 1
    time = 0
    for i in range(mid):
        if i % k == (mid - 1) % k:
            time += a[i]
    if time <= m:
        lo = mid
    else:
        hi = mid
print(lo)
