#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
using pi = pair<int, int>;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, w;
    double m;
    cin >> n >> w >> m;
    vector<vector<pair<int, double> > > adj(n);
    vector<array<int, 2> > a(n);
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist =
                    sqrt((a[i][0] - a[j][0]) * (a[i][0] - a[j][0]) +
                         (a[i][1] - a[j][1]) * (a[i][1] - a[j][1]));
            adj[i].push_back({j, dist});
            adj[j].push_back({i, dist});
        }
    }
    while (w--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        for (auto &[x,dist]: adj[u]) {
            if (x == v) {
                dist = 0;
                break;
            }
        }
        for (auto &[x,dist]: adj[v]) {
            if (x == u) {
                dist = 0;
                break;
            }
        }
    }
    vector<double> dist(n, 1e18);
    vector<int> vis(n);
    priority_queue<pair<double,int> > pq;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [cur,u] = pq.top();
        cur *= -1;
        pq.pop();
        if (u == n - 1) break;
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto &[v,d]: adj[u]) {
            if (cur + d < dist[v]) {
                dist[v] = cur + d;
                pq.emplace(-dist[v], v);
            }
        }
    }
    cout << (int) (dist[n - 1] * 1000);
}
