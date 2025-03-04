n, m = map(int, input().split())
a = []
for i in range(n):
    a.append(list(map(int, input().split())))


def do(lst):
    cur = lst[0]
    bridge = [False for _ in range(len(lst))]
    for i in range(1, len(lst)):
        if abs(cur - lst[i]) > 1:
            return False
        if lst[i] < cur:
            if i + m > n:
                return False
            for j in range(i, i + m):
                if lst[j] != cur - 1:
                    return False
                bridge[j] = True
            cur -= 1
        elif lst[i] > cur:
            if i - m < 0:
                return False
            for j in range(i - m, i):
                if bridge[j]:
                    return False
                if lst[j] != cur:
                    return False
                bridge[j] = True
            cur += 1
    return True


ans = 0
for i in range(n):
    ans += do(a[i])

for i in range(n):
    l = []
    for j in range(n):
        l.append(a[j][i])
    ans += do(l)

print(ans)
