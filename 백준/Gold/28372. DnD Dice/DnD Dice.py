import sys
def input():return sys.stdin.readline().rstrip()


dp = [1] + [0] * 999
lst = list(map(int, input().split()))

for i in range(5):
    for j in range(lst[i]):
        dpx = [0] * 1000
        t = [4, 6, 8, 12, 20][i]
        for k in range(500):
            if dp[k]:
                for r in range(t):
                    dpx[k + r + 1] += dp[k]
        dp = dpx
ans = []
for i in range(1000):
    if dp[i]:
        ans.append((-dp[i], i))
ans.sort()
ansx = []
for i in ans:
    ansx.append(i[1])
print(*ansx)