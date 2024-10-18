#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()

int dp[3005][3005];
int par[3005];
int sz[3005];
vector<int> adj[3005];
vector<int> g[3005];

void recur(int v) { // v is root, size k minimum edges to erase
    dp[v][0] = 1e9;
    dp[v][1] = v == 0 ? 0 : 1;
    for (auto &u: g[v]) {
        recur(u);
        vector<int> tmp(sz[v] + 1);
        for (int k = 1; k <= sz[v]; k++) {
            tmp[k] = dp[v][k] + 1;
            for (int x = 1; x <= min(k, sz[u]); x++) {
                tmp[k] = min(tmp[k], dp[v][k - x] + dp[u][x] - 1);
            }
        }
        for (int k = 1; k <= sz[v]; k++) dp[v][k] = tmp[k];
    }
}

void dfs(int v, int p) {
    sz[v] = 1;
    for (auto &u: adj[v]) {
        if (u == p) continue;
        g[v].push_back(u);
        par[u] = v;
        dfs(u, v);
        sz[v] += sz[u];
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) dp[i][j] = 1e9;
    }
    recur(0);
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= n; j++) cout << i << ' ' << j << ':' << dp[i][j] << '\n';
    // }
    int q;
    cin >> q;
    while (q--) {
        int x, res = 1e9;
        cin >> x;
        for (int i = 0; i < n; i++) res = min(res, dp[i][x]);
        cout << (res == 1e9 ? "-1" : to_string(res)) << '\n';
    }
}
