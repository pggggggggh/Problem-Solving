t = int(input())
for _ in range(t):
    a = list(map(int, input().split()))
    a.sort()
    if (
        a == [0, 1, 4, 5]
        or a == [1, 3, 5, 7]
        or a == [2, 3, 6, 7]
        or a == [0, 2, 4, 6]
        or a == [0, 1, 2, 3]
        or a == [4, 5, 6, 7]
    ):
        print("YES")
    else:
        print("NO")
