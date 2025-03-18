while True:
    n = int(input())
    if n == 0:
        break
    adj = [[] for _ in range(35)]
    exist = set()
    for _ in range(n):
        inp = list(map(lambda x: ord(x) - 65 + 1, list(input().split())))
        for i in range(6):
            exist.add(inp[i])
        for i in range(0, 5):
            adj[inp[5]].append(inp[i])
    idx = [-1 for _ in range(35)]
    top = [0 for _ in range(35)]
    fin = [False for _ in range(35)]
    stk = []
    sccs = []
    dfn = 0

    def dfs(u):
        global dfn
        dfn += 1
        stk.append(u)
        idx[u] = top[u] = dfn
        for v in adj[u]:
            if idx[v] == -1:
                top[u] = min(top[u], dfs(v))
            elif not fin[v]:
                top[u] = min(top[u], top[v])
        if top[u] == idx[u]:
            scc = []
            while True:
                x = stk.pop()
                fin[x] = True
                scc.append(x)
                if x == u:
                    break
            scc.sort()
            sccs.append(scc)
        return top[u]

    for i in range(1, 35):
        if i not in exist or idx[i] != -1:
            continue
        dfs(i)

    sccs.sort()
    for scc in sccs:
        for x in scc:
            print(chr(x + 65 - 1), end=" ")
        print()
    print()
