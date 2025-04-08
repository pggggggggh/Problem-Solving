from collections import Counter

n, k = map(int, input().split())
a = list(map(int, input().split()))
c = Counter(a)
n = len(c)
dp = [0 for _ in range(k + 1)]
dp[0] = 1
for i in range(n):
    for j in range(1, k + 1)[::-1]:
        dp[j] = dp[j - 1] * list(c.values())[i] + dp[j]
print(dp[k] % 998244353)
