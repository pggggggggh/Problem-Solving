n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
if a == b:
    print("POSSIBLE")
    exit(0)
for i in range(2, len(b)):
    if b[i - 2] < b[i - 1] < b[i] or b[i - 2] > b[i - 1] > b[i]:
        print("POSSIBLE")
        exit(0)
print("IMPOSSIBLE")
