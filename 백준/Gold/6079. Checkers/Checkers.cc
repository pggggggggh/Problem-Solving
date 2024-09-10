#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
using pi = pair<int, int>;

int n;
char a[40][40];
int lft;
int dx[4] = {-1, -1, 1, 1};
int dy[4] = {-1, 1, -1, 1};
vector<pi> path;

int dfs(int x, int y) {
    path.push_back({x, y});
    if (lft == 0) {
        for (auto &[x,y]: path) {
            cout << x << ' ' << y << '\n';
        }
        path.pop_back();
        return 1;
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << a[i][j];
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    int res = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        int nx2 = nx + dx[i], ny2 = ny + dy[i];
        if (a[nx][ny] != 'o') continue;
        if (nx2 < 1 || nx2 > n || ny2 < 1 || ny2 > n) continue;
        if (a[nx2][ny2] != '+') continue;

        a[x][y] = '+';
        a[nx][ny] = '+';
        a[nx2][ny2] = 'K';
        lft--;
        res = max(res, dfs(nx + dx[i], ny + dy[i]));
        a[x][y] = 'K';
        a[nx][ny] = 'o';
        a[nx2][ny2] = '+';
        lft++;
    }
    path.pop_back();
    return res;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'o') lft++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 'K') {
                if (dfs(i, j)) return 0;
            }
        }
    }
}
