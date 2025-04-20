n = int(input())
a = []

for i in range(n):
    x, y = map(int, input().split())
    a.append([x, y])
a.sort()
psum = [a[0][1]]
for i in range(1, n):
    psum.append(psum[-1] + a[i][1])
sfxmx = [0 for _ in range(n)]
cur = -(10**18)
for i in range(n)[::-1]:
    cur = max(cur, psum[i] - a[i][0])
    sfxmx[i] = cur
ans = 0
cur = 0
for i in range(n):
    ans = max(ans, sfxmx[i] + a[i][0] - cur)
    cur += a[i][1]
print(ans)
