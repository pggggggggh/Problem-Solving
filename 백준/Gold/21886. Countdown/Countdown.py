n, k = map(int, input().split())
a = list(map(int, input().split()))
psum = 0
for i in range(n - 1):
    psum += a[i]
    if (k + psum) % (i + 1) == 0:
        ans = (k + psum) // (i + 1)
        if ans > a[i] and ans <= a[i + 1]:
            print(ans)
            exit(0)
psum += a[n - 1]
print((psum + k) // n)
