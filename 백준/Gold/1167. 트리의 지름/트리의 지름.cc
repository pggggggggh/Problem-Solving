#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = array<int, 2>;

int n;
int dist[100005];
vector<pi> adj[100005];

void dfs(int v, int par) {
    for (auto &e: adj[v]) {
        const auto &[u,w] = e;
        if (u == par) continue;
        dist[u] = dist[v] + w;
        dfs(u, v);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int v, u, w;
        cin >> v;
        v--;
        while (1) {
            cin >> u;
            if (u == -1) break;
            u--;
            cin >> w;
            adj[v].push_back({u, w});
        }
    }
    dfs(0, -1);
    int mxi = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > dist[mxi]) mxi = i;
    }
    fill(dist, dist + n, 0);
    dfs(mxi, -1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dist[i]);
    }
    cout << ans;
}
