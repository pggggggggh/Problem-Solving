n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
aa = list(enumerate(a))
mxidx = 0
for i in range(n):
    if b[i] > b[mxidx]:
        mxidx = i
sorted_a = sorted(aa, key=lambda x: x[1], reverse=True)
ans = []
for i in range(n):
    if sorted_a[i][0] == mxidx:
        continue
    if sorted_a[i][1] > 0:
        ans.append(["+", mxidx + 1, sorted_a[i][1]])
for i in range(n):
    if i == mxidx:
        continue
    if b[i] > 0:
        ans.append(["+", i + 1, b[i]])

print(len(ans))
for x in ans:
    print(x[0], x[1], x[2])
