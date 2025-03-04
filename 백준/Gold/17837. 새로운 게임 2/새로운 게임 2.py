import sys


def input():
    return sys.stdin.readline().rstrip()


n, k = map(int, input().split())
a = [[2 for _ in range(n + 2)] for _ in range(n + 2)]
b = [[[] for _ in range(n + 2)] for _ in range(n + 2)]
for i in range(1, n + 1):
    ar = list(map(int, input().split()))
    for j in range(1, n + 1):
        a[i][j] = ar[j - 1]

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]
pos = [[] for _ in range(k)]
for i in range(k):
    x, y, z = map(int, input().split())
    b[x][y].append([i, z - 1])
    pos[i] = [x, y]

for turn in range(1, 1001):
    max_sz = 0

    for i in range(k):
        x, y = pos[i]
        idx = 0
        for j in range(len(b[x][y])):
            if b[x][y][j][0] == i:
                idx = j
                break
        nx = x + dx[b[x][y][idx][1]]
        ny = y + dy[b[x][y][idx][1]]

        if a[nx][ny] == 2:
            b[x][y][idx][1] ^= 1
            nx = x + dx[b[x][y][idx][1]]
            ny = y + dy[b[x][y][idx][1]]
        if a[nx][ny] == 0:
            for up in b[x][y][idx:]:
                b[nx][ny].append(up)
                pos[up[0]] = [nx, ny]
            b[x][y] = b[x][y][:idx]
            max_sz = max(max_sz, len(b[nx][ny]))
        elif a[nx][ny] == 1:
            for up in b[x][y][idx:][::-1]:
                b[nx][ny].append(up)
                pos[up[0]] = [nx, ny]
            b[x][y] = b[x][y][:idx]
            max_sz = max(max_sz, len(b[nx][ny]))

    # for ii in range(n + 2):
    #     for j in range(n + 2):
    #         print(b[ii][j], end=" ")
    #     print()
    # print()
    if max_sz >= 4:
        print(turn)
        exit(0)

print(-1)
