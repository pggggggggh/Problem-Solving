n, k = map(int, input().split())
b = list(map(int, input().split()))
c = list(map(int, input().split()))
a = []
for i in range(n):
    a.append(max(c[i] - b[i], 0))
cur = 0  # 이 인덱스가 얼마만큼의 영향을 받는가
dur = 0
imos = [0 for _ in range(10 * n)]
ans = 0
for i in range(n):
    dur += imos[i]
    cur += dur
    a[i] -= cur
    if a[i] < 0:
        continue
    to_hit = (a[i] + k - 1) // k
    ans += to_hit
    cur += to_hit * k
    dur += -to_hit
    imos[i + k + 1] += to_hit
print(ans)
