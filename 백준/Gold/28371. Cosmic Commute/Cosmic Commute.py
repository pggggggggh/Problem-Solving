import sys
def input():return sys.stdin.readline().rstrip()
from fractions import Fraction as F
from collections import deque as dq
n, m, k = map(int, input().split())
worm = list(map(lambda x:int(x) - 1, input().split()))
dist = [float('inf')] * n
distx = [float('inf')] * n
dist[0] = 0
distx[n - 1] = 0
edge = [[] for i in range(n)]
for i in range(m):
    x, y = map(lambda x:int(x) - 1, input().split())
    edge[x].append(y)
    edge[y].append(x)

d = dq()
d.append(0)
while d:
    x = d.popleft()
    for y in edge[x]:
        if dist[y] > dist[x] + 1:
            dist[y] = dist[x] + 1
            d.append(y)
d = dq()
d.append(n - 1)
while d:
    x = d.popleft()
    for y in edge[x]:
        if distx[y] > distx[x] + 1:
            distx[y] = distx[x] + 1
            d.append(y)
ans = dist[n - 1]
s = 0
for i in worm:
    s += distx[i]

for i in worm:
    ans = min(ans, dist[i] + F((s - distx[i]), k - 1))
print(ans.numerator, '/', ans.denominator, sep='')
