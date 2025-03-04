from itertools import combinations

n, k, m = map(int, input().split())

a = [[0 for _ in range(m + 2)] for _ in range(n + 2)]

for _ in range(k):
    x, y = map(int, input().split())
    a[y][x] = 1

able = []
for i in range(1, n):
    for j in range(1, m + 1):
        if not a[i][j]:
            able.append([i, j])

comb = (
    list(combinations(able, 1))
    + list(combinations(able, 2))
    + list(combinations(able, 3))
)


def go():
    for i in range(1, n + 1):
        cur = i
        for j in range(1, m + 1):
            if a[cur][j]:
                cur += 1
            elif a[cur - 1][j]:
                cur -= 1
        if cur != i:
            return False
    return True


if go():
    print(0)
    exit(0)

for c in comb:
    for x, y in c:
        a[x][y] = 1
    if go():
        print(len(c))
        exit(0)
    for x, y in c:
        a[x][y] = 0

print(-1)
