#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
using pi = pair<int, int>;

int n, m;
int a[1005][1005];
int vis[1005][1005];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void bfs(int x, int y) {
    queue<pi> q;
    q.push({x, y});
    vis[x][y] = 1;
    while (!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!vis[nx][ny] && a[nx][ny] > 0) {
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j] && a[i][j] > 0) {
                bfs(i, j);
                res++;
            }
        }
    }
    cout << res;
}
