n, ss, k = input().split()
n = int(n)
ss = float(ss)
k = int(k)
m = [0 for _ in range(k + 2)]
s = [0 for _ in range(k + 1)]
s[0] = ss
for i in range(1, k + 1):
    m[i], s[i] = input().split()
    m[i] = int(m[i])
    s[i] = float(s[i])
m[0] = 1
m[k + 1] = n + 1
res = 0
for i in range(1, k + 2):
    res += (m[i] - m[i - 1]) * 240 / s[i - 1]
print(res)
