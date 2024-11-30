#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<vector<vector<pi>>> adj(31, vector<vector<pi>>(n + 1));
	for (int i = 0; i < 31; i++) {
		for (int j = 1; j <= n; j++) {
			adj[i][j - 1].emplace_back(j, 1);
			adj[i][j].emplace_back(j - 1, 0);
		}
	}
	while (k--) {
		int w, s, e, x;
		cin >> w >> s >> e >> x;
		for (int i = 0; i < 31; i++) {
			int cur = (x >> i) & 1;
			if (w == 1 && cur == 1) {
				adj[i][s - 1].emplace_back(e, e - s + 1);
				adj[i][e].emplace_back(s - 1, -(e - s + 1));
			}
			if (w == 1 && cur == 0) {
				adj[i][s - 1].emplace_back(e, e - s);
			}
			if (w == 2 && cur == 1) {
				adj[i][e].emplace_back(s - 1, -1);
			}
			if (w == 2 && cur == 0) {
				adj[i][s - 1].emplace_back(e, 0);
				adj[i][e].emplace_back(s - 1, 0);
			}
		}
	}
	vector<vector<int>> dist(31, vector<int>(n + 1, 1e18));
	for (int i = 0; i < 31; i++) {
		dist[i][0] = 0;
		for (int j = 1; j <= n + 1; j++) {
			bool upd = false;
			for (int u = 0; u <= n; u++) {
				for (auto& [v, cost] : adj[i][u]) {
					if (dist[i][u] + cost < dist[i][v]) {
						upd = true;
						dist[i][v] = dist[i][u] + cost;
					}
				}
			}
			if (j == n + 1 && upd) {
				cout << "-1";
				return;
			}
		}
	}
	vector<int> ans(n + 1);
	for (int i = 0; i < 31; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] > dist[i][j - 1]) ans[j] |= (1LL << i);
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}