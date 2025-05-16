from collections import deque

n = int(input())
m = int(input())
a = [[0 for _ in range(m + 1)] for _ in range(n + 1)]
vis = [[0 for _ in range(m + 1)] for _ in range(n + 1)]
for i in range(1, n + 1):
    sex = list(map(int, input().split()))
    for j in range(0, m):
        a[i][j + 1] = sex[j]
k = int(input())
bodo = a[1][1]
q = deque()
q.append([1, 1])
vis[1][1] = 1

while q:
    x, y = q.popleft()
    if x == n and y == m:
        print("ALIVE")
        exit(0)
    for nx in range(x - k, x + k + 1):
        if nx < 1 or nx > n:
            continue
        for ny in range(y - k, y + k + 1):
            if ny < 1 or ny > m:
                continue
            if abs(x - nx) + abs(y - ny) > k:
                continue
            if a[nx][ny] == a[1][1]:
                if vis[nx][ny] == 0:
                    vis[nx][ny] = 1
                    q.append([nx, ny])
print("DEAD")
