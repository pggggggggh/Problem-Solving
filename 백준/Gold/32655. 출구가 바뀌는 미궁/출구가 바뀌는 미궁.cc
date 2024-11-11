#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pi>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int s, e, x;
		cin >> s >> e >> x;
		adj[s].push_back({ e, x });
		adj[e].push_back({ s, x });
	}

	int s = 1;

	vector<int> dist(n + 1, 1e18), vis(n + 1), from(n + 1, -1);
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	dist[s] = 0;
	pq.push({ 0, s });
	while (!pq.empty()) { // u -> v
		auto [d, u] = pq.top();
		pq.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto [v, cost] : adj[u]) {
			if (dist[u] + cost < dist[v]) {
				dist[v] = dist[u] + cost;
				pq.push({ dist[v], v });
				from[v] = u;
			}
		}
	}

	int t;
	cin >> t;
	int len = k * t;
	int res = 1e18;
	for (int i = 0; i < t; i++) {
		int x;
		cin >> x;
		int cycle = dist[x] / len;
		int ans;
		if ((dist[x] / k) % t == i) {
			ans = dist[x];
		} else if ((dist[x] / k) % t > i) {
			ans = (cycle + 1) * len + i * k;
		} else { // <i
			ans = (cycle)*len + i * k;
		}
		res = min(res, ans);
	}
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}