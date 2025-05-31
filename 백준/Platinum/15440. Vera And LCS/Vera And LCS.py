n, k = map(int, input().split())
a = input()
c = [0 for _ in range(26)]
for x in a:
    c[ord(x) - 97] += 1
if min(c) > k or k > n:
    print("WRONGANSWER")
else:
    d = chr(97 + c.index(min(c)))
    cnt = k-min(c)
    for x in a:
        if x == d:
            print(d, end="")
        elif cnt > 0:
            print(x, end="")
            cnt -= 1
        else:
            print(d, end="")
