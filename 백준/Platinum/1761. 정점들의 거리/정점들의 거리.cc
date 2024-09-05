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
    // given vector<vector<pi> > adj(n) of {u,dist}
const int MAX_LOG = 30;
vector<int> vis(n);
vector<int> depth(n);
vector<int> dist(n);
vector par(n, vector<int>(MAX_LOG)); // (2^j)th ancestor from i

function<void(int)> dfs = [&](int v) -> void {
    vis[v] = 1;
    for (auto &[u,d]: adj[v]) {
        if (vis[u]) continue;
        par[u][0] = v;
        depth[u] = depth[v] + 1;
        dist[u] = dist[v] + d;
        dfs(u);
    }
};
dfs(0);
for (int j = 1; j < MAX_LOG; j++) {
    for (int i = 0; i < n; i++) {
        par[i][j] = par[par[i][j - 1]][j - 1];
    }
}

function<int(int,int)> lca = [&](int v, int u) -> int {
    if (depth[v] < depth[u]) swap(v, u);
    int diff = depth[v] - depth[u];
    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (diff & (1 << i)) v = par[v][i];
    }
    if (v == u) return v;
    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (par[v][i] != par[u][i]) {
            v = par[v][i], u = par[u][i];
        }
    }
    return par[v][0];
};

function<int(int,int)> distance = [&](int v, int u) -> int {
    return dist[v] + dist[u] - 2 * dist[lca(v, u)];
};

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << distance(u, v) << '\n';
    }
}
