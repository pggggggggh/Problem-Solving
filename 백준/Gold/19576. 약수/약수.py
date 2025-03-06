n = int(input())
a = [1, *list(map(int, input().split()))]
a.sort()
dp = [1 for _ in range(n + 1)]
dp[0] = 0
for i in range(1, n + 1):
    for j in range(i):
        if a[i] % a[j] == 0:
            dp[i] = max(dp[i], dp[j] + 1)
print(n - max(dp))
