import heapq

n, m = map(int, input().split())
adj = [[] for _ in range(101)]
for i in range(1, 101):
    for j in range(i + 1, min(i + 7, 101)):
        adj[i].append([j, 1])
for _ in range(n + m):
    x, y = map(int, input().split())
    adj[x].clear()
    adj[x].append([y, 0])

dist = [10**18 for _ in range(101)]
pq = []
dist[1] = 0
heapq.heappush(pq, [0, 1])
while pq:
    d, u = heapq.heappop(pq)
    if d != dist[u]:
        continue
    for v, cost in adj[u]:
        if dist[u] + cost < dist[v]:
            dist[v] = dist[u] + cost
            heapq.heappush(pq, [dist[v], v])
print(dist[100])
