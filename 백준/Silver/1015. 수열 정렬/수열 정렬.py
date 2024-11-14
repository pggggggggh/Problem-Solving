n = int(input())
inp = list(map(int, input().split()))
a = [[inp[x], x] for x in range(n)]
a = sorted(a)
b = [0 for _ in range(n)]
for i in range(n):
    b[a[i][1]] = i
print(" ".join(map(str, b)))
