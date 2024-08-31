#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pi> > adj(n);
    while (m--) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        adj[x].push_back({y, w});
    }
    int s, e;
    cin >> s >> e;
    s--, e--;
    vector<int> dist(n, 1e18), vis(n), from(n, -1), cnt(n); // cnt : num of shortest paths
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v,cost]: adj[u]) {
            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                pq.push({dist[v], v});
                from[v] = u;
                cnt[v] = cnt[u];
            } else if (dist[u] + cost == dist[v]) cnt[v] += cnt[u];
        }
    }
    vector<int> path;
    int cur = e;
    while (cur != -1) {
        path.push_back(cur);
        cur = from[cur];
    }
    reverse(all(path));
    cout << dist[e] << '\n' << path.size() << '\n';
    for (auto &x: path) cout << x + 1 << ' ';
}
