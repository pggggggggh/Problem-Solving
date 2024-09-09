#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
using pi = pair<int, int>;

int n, m;
int a[705][705];
int vis[705][705];
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int encounter;

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if (a[nx][ny] > a[x][y]) encounter = 1;
        if (!vis[nx][ny] && a[nx][ny] == a[x][y]) dfs(nx, ny);
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
            if (!vis[i][j]) {
                encounter = 0;
                dfs(i, j);
                if (!encounter) res++;
            }
        }
    }
    cout << res;
}
