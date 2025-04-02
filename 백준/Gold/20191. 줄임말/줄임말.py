from collections import defaultdict
import bisect

a = input()
b = input()
n = len(a)
m = len(b)

pos = defaultdict(list)
for i in range(m):
    pos[b[i]].append(i)
bptr = -1
ans = 1
for aptr in range(n):
    if len(pos[a[aptr]]) == 0:
        print("-1")
        exit(0)
    idx = bisect.bisect_right(pos[a[aptr]], bptr)
    if idx == len(pos[a[aptr]]):
        bptr = -1
        idx = bisect.bisect_right(pos[a[aptr]], bptr)
        ans += 1
    bptr = pos[a[aptr]][idx]
print(ans)
