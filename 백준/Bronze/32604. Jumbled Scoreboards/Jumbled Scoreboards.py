n = int(input())
a = []
for _ in range(n):
    a.append(list(map(int, input().split())))

for i in range(1, n):
    if a[i][0] < a[i - 1][0] or a[i][1] < a[i - 1][1]:
        print("no")
        quit()

print("yes")
