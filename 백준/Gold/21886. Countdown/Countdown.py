n, k = map(int, input().split())
a = list(map(int, input().split()))
psum = 0
for i in range(n):
    psum += a[i]
    if i == 0:
        gt = -1
    else:
        gt = a[i - 1]
    leq = a[i]
    if (k + psum) % (i + 1) != 0:
        continue
    ans = (k + psum) // (i + 1)
    if ans > gt and ans <= leq:
        print(ans)
        exit(0)
print((k + psum) // n)
