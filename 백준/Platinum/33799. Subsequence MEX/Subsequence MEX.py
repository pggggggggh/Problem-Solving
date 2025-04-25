import sys


def input():
    return sys.stdin.readline().rstrip()


t = int(input())
for _ in range(t):
    a = input()
    n = len(a)
    s = ""
    for i in range(n):
        for j in range(10):
            if j == int(a[i]):
                continue
            s += str(j)
        if i < n - 1:
            if a[i] == a[i + 1]:
                s += str(a[i])
            else:
                s += str(a[i + 1]) + str(a[i])
    if n == 1:
        s += "0"
    print(s.lstrip("0"))
