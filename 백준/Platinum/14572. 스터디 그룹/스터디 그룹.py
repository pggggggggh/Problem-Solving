from collections import Counter

n, k, d = map(int, input().split())
a = []
for i in range(n):
    m, s = map(int, input().split())
    know = list(map(int, input().split()))
    a.append([s, know])
a.sort()
cnt = Counter()
l = 0
r = 0
ans = 0
for l in range(0, n):
    while r < n and a[r][0] <= a[l][0] + d:
        for x in a[r][1]:
            cnt[x] += 1
        r += 1

    afuck = 0
    bfuck = 0
    for k, v in cnt.items():
        if v == 0:
            continue
        afuck += 1
        if v == r - l:
            bfuck += 1
    ans = max(ans, (r - l) * (afuck - bfuck))

    for x in a[l][1]:
        cnt[x] -= 1
print(ans)
