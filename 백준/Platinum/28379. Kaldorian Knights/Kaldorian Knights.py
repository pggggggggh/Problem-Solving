import sys
def input():return sys.stdin.readline().rstrip()

mod = 10 ** 9 + 7
fac = [1]
for i in range(1, 10**6 + 1):
    fac.append(fac[-1] * i % mod)
n, h = map(int, input().split())
if not h:
    print(fac[n])
    quit()
ans = fac[n]
lst = [int(input()) for i in range(h)]
slst = [lst[0]]
for i in range(1, h):
    slst.append(slst[-1] + lst[i])
a = fac[lst[0]] * fac[n - lst[0]]
dp = [a]
for i in range(1, h):
    b = fac[slst[i]] * fac[n - slst[i]]
    for j in range(i):
        b -= dp[j] * pow(fac[n - slst[j]], -1, mod) * \
             (fac[slst[i] - slst[j]] * fac[n - slst[i]])
        b %= mod
    dp.append(b)

print((ans - sum(dp)) % mod)