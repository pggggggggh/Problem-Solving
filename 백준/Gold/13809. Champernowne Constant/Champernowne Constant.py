def f(x):
    add = 9
    res = 0
    for i in range(1, len(str(x))):
        res += i * add
        add *= 10
    res += len(str(x)) * (x - 10 ** (len(str(x)) - 1) + 1)

    return res


while True:
    n, k = map(int, input().split())
    realk = k
    if n == 0:
        break

    lo = 0
    hi = 10**16
    while lo + 1 < hi:
        mid = lo + hi >> 1
        if f(mid) < n:
            lo = mid
        else:
            hi = mid

    # s = ""
    # for i in range(1, 10000):
    #     s += str(i)
    # print(s[n - 1 : n + realk - 1])

    k -= len(str(lo + 1)[n - f(lo) - 1 :])
    shitcorner = str(lo + 1)[n - f(lo) - 1 :]

    cur_len = 0
    cur_num = lo + 2

    while True:
        if cur_len + len(str(cur_num)) <= k:
            shitcorner += str(cur_num)
            cur_len += len(str(cur_num))
        else:
            shitcorner += str(cur_num)[: k - cur_len]
            break
        cur_num += 1
    print(shitcorner[:realk])
