class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        struct state {
            int x,y,left,dist;
        };
        queue<state> q;
        vector<vector<vector<int>>> vis(n,vector<vector<int>>(m,vector<int>(k+1)));
        q.push({0,0,k,0});
        vis[0][0][k] = 1;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        while (!q.empty()) {
            auto [x,y,left,dist] = q.front();
            q.pop();
            if (x==n-1 && y==m-1) {
                return dist;
            }
            for (int i=0;i<4;i++) {
                int nx = x+dx[i], ny = y+dy[i];
                if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
                int nl = left;
                if (grid[nx][ny] == 1) nl--;
                if (nl<0) continue;
                if (vis[nx][ny][nl]) continue;
                vis[nx][ny][nl] = 1;
                q.push({nx,ny,nl,dist+1});
            }
        }
        return -1;
    }
};