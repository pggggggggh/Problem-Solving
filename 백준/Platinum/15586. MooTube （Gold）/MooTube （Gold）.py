n, q = map(int, input().split())
e = []
for i in range(n - 1):
    x, y, z = map(int, input().split())
    e.append([x, y, z])
e.sort(key=lambda x: -x[2])
qry = []
for i in range(q):
    x, y = map(int, input().split())
    qry.append([x, y, i])
qry.sort(key=lambda x: -x[0])
ans = [0 for _ in range(q)]

par = [i for i in range(n + 1)]
sz = [1 for i in range(n + 1)]


def find(x):
    if par[x] == x:
        return x
    par[x] = find(par[x])
    return par[x]


def uni(x, y):
    x = find(x)
    y = find(y)
    if x == y:
        return
    sz[x] += sz[y]
    par[y] = x


ptr = 0
for x, y, i in qry:
    while ptr < n - 1 and e[ptr][2] >= x:
        uni(e[ptr][0], e[ptr][1])
        ptr += 1
    ans[i] = sz[find(y)]
for x in ans:
    print(x - 1)
