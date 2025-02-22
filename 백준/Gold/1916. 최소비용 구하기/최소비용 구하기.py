import heapq

n = int(input())
m = int(input())
adj = [[] for i in range(n + 1)]
for i in range(m):
    x, y, z = map(int, input().split())
    adj[x].append([y, z])
s, e = map(int, input().split())

pq = []
vis = [False for i in range(n + 1)]
dist = [10**18 for i in range(n + 1)]
dist[s] = 0
heapq.heappush(pq, [0, s])

while pq:
    d, u = pq[0]
    heapq.heappop(pq)
    if vis[u]:
        continue
    vis[u] = True

    for v, cost in adj[u]:
        if dist[u] + cost < dist[v]:
            dist[v] = dist[u] + cost
            heapq.heappush(pq, [dist[v], v])
print(dist[e])
