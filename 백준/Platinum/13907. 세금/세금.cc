#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;

struct edge {
    int to, cost;
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, s, d;
    cin >> n >> m >> k;
    cin >> s >> d;
    vector<vector<edge> > adj(n + 1);
    for (int i = 0; i < m; i++) {
        int s, e, x;
        cin >> s >> e >> x;
        adj[s].push_back({e, x});
        adj[e].push_back({s, x});
    }
    vector dist(n + 1, vector<int>(2 * n, 1e9));
    vector vis(n + 1, vector<int>(n + 1));
    priority_queue<array<int, 3>, vector<array<int, 3> >, greater<array<int, 3> > > pq;
    dist[s][0] = 0;
    pq.push({0, s, 0});
    while (!pq.empty()) {
        auto [d,v,edges] = pq.top();
        pq.pop();
        if (vis[v][edges]) continue;
        vis[v][edges] = 1;
        for (auto &e: adj[v]) {
            const auto &[u,cost] = e;
            if (dist[v][edges] + cost < dist[u][edges + 1]) {
                dist[u][edges + 1] = dist[v][edges] + cost;
                pq.push({dist[u][edges + 1], u, edges + 1});
            }
        }
    }
    int mn = 1e9;
    for (int i = 0; i < n; i++) {
        mn = min(mn, dist[d][i]);
    }
    cout << mn << '\n';
    int tax = 0;
    while (k--) {
        int x;
        cin >> x;
        tax += x;
        int mn = 1e9;
        for (int i = 0; i < n; i++) {
            mn = min(mn, dist[d][i] + tax * i);
        }
        cout << mn << '\n';
    }
}
