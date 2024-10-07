#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<pi>> adj(n + 2);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		adj[i].emplace_back(n + 1, -x);
		adj[n + 1].emplace_back(i, -x);
	}
	for (int i = 0; i < m; i++) {
		int s, e, x;
		cin >> s >> e >> x;
		adj[s].emplace_back(e, x);
		adj[e].emplace_back(s, x);
	}
	vector<int> dist(n + 2, 1e18);
	vector<int> vis(n + 2);
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	dist[n + 1] = 0;
	pq.emplace(0, n + 1);
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto &[v, cost] : adj[u]) {
			if (d + cost < dist[v]) {
				dist[v] = d + cost;
				pq.emplace(dist[v], v);
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << -dist[i] << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}