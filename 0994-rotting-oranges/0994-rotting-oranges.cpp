class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<array<int,3>> q;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (grid[i][j] == 2) q.push({i,j,0});
            }
        }

        int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
        int res = 0;
        while (!q.empty()) {
            auto [x,y,time] = q.front();
            res = time;
            q.pop();

            for (int i=0;i<4;i++) {
                int nx = x+dx[i], ny = y+dy[i];
                if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if (grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({nx,ny,time+1});
                }
            }
        }

        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return res;
    }
};