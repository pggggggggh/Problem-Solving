import math

r = int(input())
ans = 0
for g in range(1, r + 1):
    if (r + g) % g != 0:
        continue
    for x in range(g, g + r, g):
        y = r + g - x
        if math.gcd(x, y) == g and x <= y:
            ans += 1
print(ans)
