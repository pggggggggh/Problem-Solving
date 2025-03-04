n, m = map(int, input().split())
a = [*map(int, input().split())]
b = [*map(int, input().split())]
dp = [-(10**18) for _ in range(10005)]
dp[0] = 0
for i in range(n):
    for j in range(10005)[::-1]:
        if j - b[i] >= 0:
            dp[j] = max(dp[j], dp[j - b[i]] + a[i])
for i in range(10005):
    if dp[i] >= m:
        print(i)
        exit(0)
