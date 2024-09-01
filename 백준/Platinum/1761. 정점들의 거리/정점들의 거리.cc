#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<pi> > adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    const int MAX_LOG = 30;
    vector<int> vis(n);
    vector<int> depth(n);
    vector<int> dist(n);
    vector par(n, vector<int>(MAX_LOG)); // (2^j)th ancestor from i

    function<void(int)> dfs = [&](int u) -> void {
        vis[u] = 1;
        for (auto &[v,d]: adj[u]) {
            if (vis[v]) continue;
            par[v][0] = u;
            depth[v] = depth[u] + 1;
            dist[v] = dist[u] + d;
            dfs(v);
        }
    };
    dfs(0);
    for (int j = 1; j < MAX_LOG; j++) {
        for (int i = 0; i < n; i++) {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }

    function<int(int,int)> lca = [&](int u, int v) -> int {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int i = MAX_LOG - 1; i >= 0; i--) {
            if (diff & (1 << i)) u = par[u][i];
        }
        if (u == v) return u;
        for (int i = MAX_LOG - 1; i >= 0; i--) {
            if (par[u][i] != par[v][i]) {
                u = par[u][i], v = par[v][i];
            }
        }
        return par[u][0];
    };

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << dist[u] + dist[v] - dist[lca(u, v)] * 2 << '\n';
    }
}
