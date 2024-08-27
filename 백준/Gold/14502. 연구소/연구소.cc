#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

int n, m;
int a[8][8];
int go() {
    int res = 0;
    queue<pi> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 2) q.emplace(i, j);
            else if (a[i][j] == 0) res++;
        }
    }
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int vis[8][8] = {0};
    while (!q.empty()) {
        const auto &[x,y] = q.front();
        q.pop();
        vis[x][y] = 1;
        if (a[x][y] != 2) res--;
        for (int i = 0; i < 4; i++) {
            if (x + dx[i] < 0 || x + dx[i] >= n || y + dy[i] < 0 || y + dy[i] >= m) continue;
            if (vis[x + dx[i]][y + dy[i]]) continue;
            if (a[x + dx[i]][y + dy[i]] != 0) continue;
            vis[x + dx[i]][y + dy[i]] = 1;
            q.emplace(x + dx[i], y + dy[i]);
        }
    }
    return res;
}

signed main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n * m; i++) {
        if (a[i / m][i % m]) continue;
        a[i / m][i % m] = 1;
        for (int j = i + 1; j < n * m; j++) {
            if (a[j / m][j % m]) continue;
            a[j / m][j % m] = 1;
            for (int k = j + 1; k < n * m; k++) {
                if (a[k / m][k % m]) continue;
                a[k / m][k % m] = 1;
                ans = max(ans, go());
                a[k / m][k % m] = 0;
            }
            a[j / m][j % m] = 0;
        }
        a[i / m][i % m] = 0;
    }
    cout << ans;
}
