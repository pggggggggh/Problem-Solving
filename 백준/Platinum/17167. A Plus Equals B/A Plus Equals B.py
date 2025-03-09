import math
import random

a, b = map(int, input().split())
g = math.gcd(a, b)
a, b = a // g, b // g
ans = []
while a % 2 == 0:
    ans.append("B+=B")
    a //= 2
while b % 2 == 0:
    ans.append("A+=A")
    b //= 2

if a != 1:
    while True:
        bi = 1 << a.bit_length()
        toadd = 0
        fail = False
        while True:
            if (bi - a) % b == 0:
                toadd = (bi - a) // b
                break
            bi *= 2
            if bi > 10**128:
                fail = True
                break
        if not fail:
            break

        if random.random() >= 0.5:
            ans.append("A+=B")
            a += b
        else:
            ans.append("B+=A")
            b += a
        while a % 2 == 0:
            ans.append("B+=B")
            a //= 2
        while b % 2 == 0:
            ans.append("A+=A")
            b //= 2
        g = math.gcd(a, b)
        a, b = a // g, b // g

    for i in range(toadd.bit_length()):
        if (toadd >> i) & 1:
            ans.append("A+=B")
            a += b

        ans.append("B+=B")
        b += b

    for i in range(a.bit_length() - 1):
        ans.append("B+=B")
        b += b

a, b = 1, b // a

tomakelen = b.bit_length()
tomake = (1 << tomakelen) - b
for i in range(tomakelen):
    if (tomake >> i) & 1:
        ans.append("B+=A")
        b += a

    ans.append("A+=A")
    a += a

print(len(ans))

for x in ans:
    print(x)
