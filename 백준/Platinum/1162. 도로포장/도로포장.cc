#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pi> > adj(n);
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    vector<vector<int> > vis(n, vector<int>(k + 1));
    vector<vector<int> > dp(n, vector<int>(k + 1, 1e18));
    priority_queue<array<int, 3>, vector<array<int, 3> >, greater<array<int, 3> > > q;
    q.push({0, 0, 0});
    dp[0][0] = 0;
    while (!q.empty()) {
        auto [cost,v,road] = q.top();
        q.pop();
        if (vis[v][road]) continue;
        vis[v][road] = 1;
        for (auto &[u,c]: adj[v]) {
            if (road + 1 <= k) {
                if (cost < dp[u][road + 1]) {
                    dp[u][road + 1] = cost;
                    q.push({dp[u][road + 1], u, road + 1});
                }
            }
            if (cost + c < dp[u][road]) {
                dp[u][road] = cost + c;
                q.push({dp[u][road], u, road});
            }
        }
    }
    int res = 1e18;
    for (int i = 0; i <= k; i++) {
        res = min(res, dp[n - 1][i]);
    }
    cout << res;
}
