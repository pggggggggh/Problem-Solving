import itertools
import copy

n = int(input())
a = [[-1 for i in range(n + 2)]]
for _ in range(n):
    a.append([-1, *map(int, input().split()), -1])
a.append([-1 for i in range(n + 2)])


dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def move(dir):
    vis = [[False for _ in range(n + 2)] for _ in range(n + 2)]
    if dir == 0:
        for y in range(1, n + 1):
            for x in range(1, n + 1):
                if a[x][y] > 0:
                    for k in range(1, x + 1)[::-1]:
                        if a[k - 1][y] == a[x][y] and not vis[k - 1][y]:
                            a[k - 1][y] *= 2
                            a[x][y] = 0
                            vis[k - 1][y] = True
                            break
                        if a[k - 1][y] != 0:
                            if k is not x:
                                a[k][y] = a[x][y]
                                a[x][y] = 0
                            break
    elif dir == 1:
        for y in range(1, n + 1):
            for x in range(1, n + 1)[::-1]:
                if a[x][y] > 0:
                    for k in range(x, n + 1):
                        if a[k + 1][y] == a[x][y] and not vis[k + 1][y]:
                            a[k + 1][y] *= 2
                            a[x][y] = 0
                            vis[k + 1][y] = True
                            break
                        if a[k + 1][y] != 0:
                            if k is not x:
                                a[k][y] = a[x][y]
                                a[x][y] = 0
                            break
    elif dir == 2:
        for x in range(1, n + 1):
            for y in range(1, n + 1):
                if a[x][y] > 0:
                    for k in range(1, y + 1)[::-1]:
                        if a[x][k - 1] == a[x][y] and not vis[x][k - 1]:
                            a[x][k - 1] *= 2
                            a[x][y] = 0
                            vis[x][k - 1] = True
                            break
                        if a[x][k - 1] != 0:
                            if k is not y:
                                a[x][k] = a[x][y]
                                a[x][y] = 0
                            break
    else:
        for x in range(1, n + 1):
            for y in range(1, n + 1)[::-1]:
                if a[x][y] > 0:
                    for k in range(y, n + 1):
                        if a[x][k + 1] == a[x][y] and not vis[x][k + 1]:
                            a[x][k + 1] *= 2
                            a[x][y] = 0
                            vis[x][k + 1] = True
                            break
                        if a[x][k + 1] != 0:
                            if k is not y:
                                a[x][k] = a[x][y]
                                a[x][y] = 0
                            break


perm = list(itertools.product([0, 1, 2, 3], repeat=5))
b = copy.deepcopy(a)
ans = 0

for p in perm:
    a = copy.deepcopy(b)
    for dir in p:
        move(dir)
    ans = max(ans, *map(max, a))
print(ans)
