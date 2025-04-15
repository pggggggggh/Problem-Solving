n, t = map(int, input().split())
imos = [0 for _ in range(100005)]
people = [0 for _ in range(100005)]
psum = [0 for _ in range(100005)]
for i in range(n):
    k = int(input())
    for j in range(k):
        x, y = map(int, input().split())
        imos[x] += 1
        imos[y] -= 1
cur = 0
for i in range(100005):
    cur += imos[i]
    people[i] = cur
    if i == 0:
        psum[i] = cur
    else:
        psum[i] = psum[i - 1] + cur
ans = psum[t - 1]
e = t
for i in range(t, 100005):
    tmp = psum[i] - psum[i - t]
    if tmp > ans:
        ans = tmp
        e = i + 1
print(e - t, e)
