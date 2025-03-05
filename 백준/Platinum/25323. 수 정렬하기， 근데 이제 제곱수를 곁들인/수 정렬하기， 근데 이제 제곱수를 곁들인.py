import bisect
import math

n = int(input())
a = list(map(int, input().split()))
b = sorted(a)
for i in range(n):
    idx = bisect.bisect_left(b, a[i])
    sibal = a[i] * a[idx]
    if (math.isqrt(sibal) ** 2) != sibal:
        print("NO")
        exit(0)
print("YES")
