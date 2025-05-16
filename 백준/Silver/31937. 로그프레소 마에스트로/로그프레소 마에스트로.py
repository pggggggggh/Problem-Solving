n, m, k = map(int, input().split())
sex = list(map(int, input().split()))
bad = [0 for _ in range(n + 1)]
for x in sex:
    bad[x] = 1
log = []
for i in range(m):
    x, y, z = map(int, input().split())
    log.append([x, y, z])
log.sort()
for i in range(1, n + 1):
    nowbad = [0 for _ in range(n + 1)]
    nowbad[i] = 1
    for foo, x, y in log:
        if nowbad[x]:
            nowbad[y] = 1
    if bad == nowbad:
        print(i)
        exit(0)
