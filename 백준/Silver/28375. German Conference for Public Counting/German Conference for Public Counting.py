n = int(input())
if n < 10:
    print(n + 1)
else:
    l = len(str(n))
    ans = l - 1
    for i in range(1, 10):
        if n >= int(str(i) * l):
            ans += l
        else:
            ans += l - 1
    print(ans)