import sys
def input():return sys.stdin.readline().rstrip()
from random import choice
def ccw(p1, p2, p3):
    x1, y1 = p1
    x2, y2 = p2
    x3, y3 = p3
    return x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3)

n = int(input())
if n < 7:
    print('possible')
else:
    point = [tuple(map(int, input().split())) for i in range(n)]

    for _ in range(100):
        p = []
        while len(p) < 2:
            t = choice(point)
            if t not in p:
                p.append(t)
        p1, p2 = p
        pointx = []
        for px in point:
            if ccw(p1, p2, px):
                pointx.append(px)

        if len(pointx) < 5:
            print('possible')
            break
        else:
            for _ in range(100):
                p = []
                while len(p) < 2:
                    t = choice(pointx)
                    if t not in p:
                        p.append(t)
                p1, p2 = p
                pointy = []
                for px in pointx:
                    if ccw(p1, p2, px):
                        pointy.append(px)
                if len(pointy) < 3:
                    print('possible')
                    break
                else:
                    for py in pointy:
                        if ccw(pointy[0], pointy[1], py):
                            break
                    else:
                        print('possible')
                        break
            else:
                continue
            break

    else:
        print('impossible')