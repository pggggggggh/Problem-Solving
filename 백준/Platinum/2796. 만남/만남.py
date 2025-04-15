def sibal(x1, y1, x2, y2, x3, y3, x4, y4):
    xsibal = max(x1, x3) - min(x2, x4)
    ysibal = max(y1, y3) - min(y2, y4)
    return max(xsibal, ysibal)


def sibal2(x1, y1, x2, y2, x3, y3, x4, y4):
    return [max(x1, x3), max(y1, y3), min(x2, x4), min(y2, y4)]


n = int(input())
cur_square = [0, 0, 0, 0]

ans = 0
for i in range(n):
    x, y, z = map(int, input().split())
    if i == 0:
        cur_square = [x - z, y - z, x + z, y + z]
        continue
    dist = sibal(*cur_square, x - z, y - z, x + z, y + z)
    if dist <= 0:
        cur_square = sibal2(*cur_square, x - z, y - z, x + z, y + z)
    else:
        cur_x1 = cur_square[0] - dist
        cur_y1 = cur_square[1] - dist
        cur_x2 = cur_square[2] + dist
        cur_y2 = cur_square[3] + dist
        cur_square = sibal2(cur_x1, cur_y1, cur_x2, cur_y2, x - z, y - z, x + z, y + z)
        ans += dist
print(ans)
