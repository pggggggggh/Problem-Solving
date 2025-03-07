from collections import deque

def solution(rectangle, characterX, characterY, itemX, itemY):
    for i,x in enumerate(rectangle):
        rectangle[i] = [x[0]*2,x[1]*2,x[2]*2,x[3]*2]
    characterX *= 2
    characterY *= 2
    itemX *= 2
    itemY *= 2
    answer = 0
    mx = 200
    intersect = [[0 for _ in range(mx)] for _ in range(mx)]
    side = [[0 for _ in range(mx)] for _ in range(mx)]
    a = [[0 for _ in range(mx)] for _ in range(mx)]
    for x1,y1,x2,y2 in rectangle:
        for i in range(x1+1,x2):
            for j in range(y1+1,y2):
                intersect[i][j] += 1
        for i in range(x1,x2+1):
            side[i][y1] = 1
            side[i][y2] = 1
        for i in range(y1,y2+1):
            side[x1][i] = 1
            side[x2][i] = 1
    
    for i in range(mx):
        for j in range(mx):
            if side[i][j] == 1 and intersect[i][j] == 0:
                a[i][j] = 1
    
    q = deque()
    vis = [[False for _ in range(mx)] for _ in range(mx)]
    q.append([characterX,characterY,0])
    vis[characterX][characterY] = True
    dx = [-1,1,0,0]
    dy = [0,0,-1,1]
    while q:
        x,y,d = q.popleft()
        if (x,y) == (itemX,itemY):
            return d//2
            
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if a[nx][ny] == 0 or vis[nx][ny]:
                continue
            q.append([nx,ny,d+1])
            vis[nx][ny] = True
            