a = input()
s = 1
for i in range(1, len(a)):
    if a[i] != a[i - 1]:
        s = i
        break
a = a[s - 1 :]
for i in range(1, len(a)):
    if a[i] == a[i - 1]:
        print(i)
        exit(0)
print(len(a))
