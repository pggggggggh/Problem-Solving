import bisect

lst = [0]
for i in range(1, 1001):
    lst.append(3 * i * (i - 1) + 1)

n, m = map(int, input().split())
a = list(map(int, input().split()))
q = list(map(int, input().split()))
a.sort()
for x in q:
    solve = bisect.bisect_right(a, x)
    print(bisect.bisect_right(lst, solve) - 1, end=" ")
