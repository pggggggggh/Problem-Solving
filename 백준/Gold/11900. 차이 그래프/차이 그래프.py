from collections import deque
import sys


def input():
    return sys.stdin.readline().rstrip()


n = int(input())
a = [0, *map(int, input().split())]
qr = int(input())

dist = [10**18 for _ in range(n)]
q = deque([[0, 0]])
dist[0] = 0
while q:
    d, u = q.popleft()
    if d > dist[u]:
        continue
    for i in range(1, n):
        if a[i] == 0:
            continue
        v = (u - i + n) % n
        if d + a[i] < dist[v]:
            dist[v] = d + a[i]
            q.append([dist[v], v])

for _ in range(qr):
    x, y = map(int, input().split())
    ans = dist[(y - x + n) % n]
    print(-1 if ans == 10**18 else ans)
