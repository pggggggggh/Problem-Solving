#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, m, p, g;
	cin >> n >> m >> p >> g;
	vector<int> pos;
	vector<int> people;
	for (int i = 0; i < p; i++) {
		int x;
		cin >> x;
		pos.push_back(x);
		people.push_back(x);
	}
	pos.push_back(1);
	sort(all(pos));
	pos.erase(unique(all(pos)), pos.end());
	vector<vector<pi>> adj(n + 1);
	vector<vector<int>> dist(pos.size(), vector<int>(n + 1, 1e18));
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].push_back({ y, z });
		adj[y].push_back({ x, z });
	}
	for (int i = 0; i < pos.size(); i++) {
		const int s = pos[i];
		dist[i][s] = 0;
		priority_queue<pi, vector<pi>, greater<pi>> pq;
		pq.push({ 0, s });
		while (!pq.empty()) {
			auto [d, u] = pq.top();
			pq.pop();
			if (dist[i][u] < d) continue;
			for (auto& [v, cost] : adj[u]) {
				if (d + cost < dist[i][v]) {
					dist[i][v] = d + cost;
					pq.push({ dist[i][v], v });
				}
			}
		}
	}
	int ans = 1e18;
	for (int i = 1; i <= n; i++) {
		int cur = 0;
		for (auto& x : people) {
			int idx = lower_bound(all(pos), x) - pos.begin();
			if (dist[idx][i] + dist[0][i] <= dist[0][x]) cur += min(dist[idx][1], g + dist[idx][i]);
			else cur += dist[idx][1];
		}
		ans = min(ans, cur);
	}
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}