import sys

n, t = map(int, input().split())
if t == 0:
    print("!", n // 2)
    sys.stdout.flush()
    for i in range(n // 2):
        a, b = map(int, input().split())
        print(b, a)
        sys.stdout.flush()
else:
    print("!", n // 2 + 1)
    print("1 1")
    sys.stdout.flush()
    for i in range(n // 2 - 1):
        a, b = map(int, input().split())
        print(b, a)
        sys.stdout.flush()
    a, b = map(int, input().split())
