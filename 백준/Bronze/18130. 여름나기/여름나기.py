n, q = map(int, input().split())
res = 0
idx = -1
for i in range(1, n + 1):
    p, k, c = map(int, input().split())
    t = (q - 1) // k
    cur = p + t * (t + 1) // 2 * c
    if idx == -1 or cur < res:
        idx = i
        res = cur
print(idx, res)
