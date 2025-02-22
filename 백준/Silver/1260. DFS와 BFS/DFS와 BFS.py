import sys
from collections import deque


def input():
    return sys.stdin.readline().rstrip()


def dfs(u):
    vis[u] = 1
    print(u, end=" ")
    for v in adj[u]:
        if not vis[v]:
            dfs(v)


n, m, k = map(int, input().split())

adj = [[] for i in range(n + 1)]
for i in range(m):
    x, y = map(int, input().split())
    adj[x].append(y)
    adj[y].append(x)
for i in range(n + 1):
    adj[i].sort()

vis = [False for i in range(n + 1)]
dfs(k)

print("")
q = deque([k])
vis = [False for i in range(n + 1)]
while q:
    u = q.popleft()
    if vis[u]:
        continue
    print(u, end=" ")
    vis[u] = 1
    for v in adj[u]:
        q.append(v)
