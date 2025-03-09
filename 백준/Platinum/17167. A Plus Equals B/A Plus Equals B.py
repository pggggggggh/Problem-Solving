import math

a, b = map(int, input().split())
g = math.gcd(a, b)
a, b = a // g, b // g

ans = []
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
