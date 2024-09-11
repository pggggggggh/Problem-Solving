#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

int n, m;
int sx, sy, ex, ey;
char a[105][105];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

inline int pos(int x, int y) {
    return m * (x - 1) + y;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'C') {
                if (sx == 0) {
                    sx = i, sy = j;
                } else {
                    ex = i, ey = j;
                }
            }
        }
    }
    vector<vector<int> > vis(n * m + 1, vector<int>(5));
    vector<vector<int> > dist(n * m + 1, vector<int>(5, 1e9));
    priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
    dist[pos(sx, sy)][4] = 0;
    pq.push({0, sx, sy, 4});
    while (!pq.empty()) {
        int cur_dist = pq.top()[0];
        int x = pq.top()[1];
        int y = pq.top()[2];
        int past_dir = pq.top()[3];
        // cout << cur_dist << ' ' << x << ' ' << y << ' ' << past_dir << '\n';
        pq.pop();
        if (x == ex && y == ey) {
            cout << cur_dist - 1 << '\n';
            break;
        }
        if (vis[pos(x, y)][past_dir]) continue;
        vis[pos(x, y)][past_dir] = 1;
        for (int i = 0; i < 4; i++) {
            int cost = 0;
            if (i != past_dir) cost = 1;
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (a[nx][ny] == '*') continue;
            if (cur_dist + cost < dist[pos(nx, ny)][i]) {
                dist[pos(nx, ny)][i] = cur_dist + cost;
                pq.push({cur_dist + cost, nx, ny, i});
            }
        }
    }
}
