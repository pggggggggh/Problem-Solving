from collections import deque

n, m, k = map(int, input().split())
adj = [[] for _ in range(n + 1)]
s, e = map(int, input().split())
for i in range(m):
    x, y, z = map(int, input().split())
    adj[x].append([y, z])
    adj[y].append([x, z])
dp = [[10**18 for _ in range(n + 5)] for _ in range(n + 1)]
q = deque([[0, s, 0]])
dp[s][0] = 0
while q:
    d, u, w = q.popleft()
    if w >= n - 1:
        continue
    if d > dp[u][w]:
        continue
    for v, cost in adj[u]:
        if dp[v][w + 1] > dp[u][w] + cost:
            dp[v][w + 1] = dp[u][w] + cost
            q.append([dp[v][w + 1], v, w + 1])
cur = 0
ans = 10**18
for i in range(1, n):
    ans = min(ans, cur * i + dp[e][i])
print(ans)

for _ in range(k):
    x = int(input())
    cur += x
    ans = 10**18
    for i in range(1, n):
        ans = min(ans, cur * i + dp[e][i])
    print(ans)
