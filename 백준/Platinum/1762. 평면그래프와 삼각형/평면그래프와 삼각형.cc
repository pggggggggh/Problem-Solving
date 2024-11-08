#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<pi> edges;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		edges.emplace_back(x, y);
	}
	for (int i = 1; i <= n; i++) sort(all(adj[i]));
	int res = 0;
	for (auto [x, y] : edges) {
		if (adj[x].size() > adj[y].size()) swap(x, y);
		for (auto& u : adj[x]) {
			res += binary_search(all(adj[y]), u);
		}
	}
	cout << res / 3;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}