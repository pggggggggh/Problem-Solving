#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

int n, m, k;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
char dc[4] = {'E', 'N', 'S', 'W'};
// E N S W
int hay[2005][2005];
int dp[70][70][35]; // x, y:-30~30까지이므로 +30해서 처리
int nxt[70][70][35];

int recur(int x, int y, int left) {
    int &ret = dp[x + 30][y + 30][left];
    if (ret != -1) return ret;

    ret = hay[1001 + x][1001 + y];
    if (left == 0) return ret;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int cur = recur(nx, ny, left - 1) + hay[1001 + x][1001 + y];
        if (cur > ret) {
            nxt[x + 30][y + 30][left] = i;
            ret = cur;
        }
    }
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    vector<pi> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        for (auto &[cx,cy]: cows) {
            hay[x + 1001 - cx][y + 1001 - cy]++;
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << recur(0, 0, k) << '\n';
    int curx = 0, cury = 0;
    while (k) {
        int p = nxt[curx + 30][cury + 30][k];
        cout << dc[p];
        curx += dx[p], cury += dy[p];
        k--;
    }
}
