import copy
from collections import deque

n, q = map(int, input().split())
n = pow(2, n)
a = [[0 for _ in range(n + 2)] for _ in range(n + 2)]
for i in range(1, n + 1):
    a[i] = [0, *map(int, input().split()), 0]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
ls = list(map(int, input().split()))
for l in ls:
    l = pow(2, l)
    new_a = [[0 for _ in range(n + 2)] for _ in range(n + 2)]
    for x in range(1, n + 1, l):
        for y in range(1, n + 1, l):
            for i in range(x, x + l):
                for j in range(y, y + l):
                    new_a[i][j] = a[x + l - 1 - (j - y)][y + i - x]
    a = copy.deepcopy(new_a)
    toerase = []
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            cnt = 0
            for k in range(4):
                if a[i + dx[k]][j + dy[k]] > 0:
                    cnt += 1
            if cnt < 3:
                toerase.append([i, j])
    for i, j in toerase:
        if a[i][j] > 0:
            a[i][j] -= 1

vis = [[False for _ in range(n + 2)] for _ in range(n + 2)]
ans = 0

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if vis[i][j] or a[i][j] == 0:
            continue
        q = deque()
        q.append([i, j])
        vis[i][j] = True
        cur = 0
        while q:
            x, y = q.popleft()
            cur += 1
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if vis[nx][ny] or a[nx][ny] == 0:
                    continue
                vis[nx][ny] = True
                q.append([nx, ny])
        ans = max(cur, ans)


print(sum(map(sum, a)))
print(ans)
