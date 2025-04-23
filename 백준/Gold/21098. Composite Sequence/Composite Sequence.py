import math

n = int(input())
a = list(map(int, input().split()))
if max(a) == 1:
    if n <= 3:
        print("No")
    else:
        print("Yes")
    exit(0)

if n >= 3:
    print("Yes")
    exit(0)


def sibal(x):
    sib = False
    for i in range(2, math.isqrt(x) + 1):
        if x % i == 0:
            sib = True
            break
    return sib


if n == 1:
    if sibal(a[0]):
        print("Yes")
    else:
        print("No")
elif sibal(a[0]) or sibal(a[1]) or sibal(a[0] + a[1]):
    print("Yes")
else:
    print("No")
