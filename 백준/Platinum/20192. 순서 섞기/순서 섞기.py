from collections import deque

n = int(input())
a = list(map(int, input().split()))
if a == sorted(a):
    print(0)
    exit(0)
ans = 0

while True:
    ans += 1
    dq = deque(a)
    a = []
    fuck = False
    cur = 0
    inc = True
    while dq:
        if inc:
            if dq[0] < cur and dq[-1] < cur:
                inc = not inc
            elif dq[0] >= cur and dq[-1] >= cur:
                if dq[0] < dq[-1]:
                    a.append(dq.popleft())
                else:
                    a.append(dq.pop())
            elif dq[0] < dq[-1]:
                a.append(dq.pop())
            else:
                a.append(dq.popleft())
        else:
            if dq[0] > cur and dq[-1] > cur:
                inc = not inc
            elif dq[0] <= cur and dq[-1] <= cur:
                if dq[0] > dq[-1]:
                    a.append(dq.popleft())
                else:
                    a.append(dq.pop())
            elif dq[0] > dq[-1]:
                a.append(dq.pop())
            else:
                a.append(dq.popleft())
        cur = a[-1]
        if not inc:
            fuck = True
    # print(a)
    if not fuck:
        break

print(ans)
