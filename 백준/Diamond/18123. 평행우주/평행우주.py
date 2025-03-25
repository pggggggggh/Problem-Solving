nn = int(input())
sibal = set()
for _ in range(nn):
    n = int(input())
    adj = [[] for _ in range(n)]
    for i in range(n - 1):
        x, y = map(int, input().split())
        adj[x].append(y)
        adj[y].append(x)
    sz = [1 for _ in range(n)]

    def dfs(u, p):
        for v in adj[u]:
            if v == p:
                continue
            dfs(v, u)
            sz[u] += sz[v]

    dfs(0, -1)

    cents = []

    def get_cents(u, p):
        is_cent = True
        for v in adj[u]:
            if v == p:
                continue
            if sz[v] > n // 2:
                is_cent = False
            get_cents(v, u)
        if n - sz[u] > n // 2:
            is_cent = False
        if is_cent:
            cents.append(u)

    get_cents(0, -1)

    def do_fuck(u, p):
        rets = []
        for v in adj[u]:
            if v == p:
                continue
            rets.append(do_fuck(v, u))
        rets.sort()
        return f"({''.join(rets)})"

    ans = do_fuck(cents[0], -1)
    for cent in cents[1:]:
        ans = min(ans, do_fuck(cent, -1))
    sibal.add(ans)
print(len(sibal))
