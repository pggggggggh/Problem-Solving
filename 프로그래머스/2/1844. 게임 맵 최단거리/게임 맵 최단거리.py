import heapq

def solution(maps):
    n = len(maps)
    m = len(maps[0])
    print(n,m)
    a = [[0 for _ in range(m+2)] for _ in range(n+2)]
    for i in range(1,n+1):
        for j in range(1,m+1):
            a[i][j] = maps[i-1][j-1]
    
    dist = [[10**18 for _ in range(m+2)] for _ in range(n+2)]
    vis = [[False for _ in range(m+2)] for _ in range(n+2)]
    q = []
    heapq.heappush(q,[0,1,1])
    dx = [-1,1,0,0]
    dy = [0,0,-1,1]
    dist[1][1] = 1
    print(a)
    while q:
        d,x,y = heapq.heappop(q)
        if vis[x][y]:
            continue
        vis[x][y] = True
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if a[nx][ny] == 1 and dist[nx][ny] > dist[x][y]+1:
                dist[nx][ny] = dist[x][y]+1
                heapq.heappush(q,[dist[nx][ny],nx,ny])
    return -1 if dist[n][m] == 1e18 else dist[n][m]