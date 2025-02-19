#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, m, v;
	cin >> n >> m >> v;
	vector<vector<int>> adj(n + 1);
	while (m--) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(all(adj[i]));
	}
	vector<int> vis(n + 1);
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;
		cout << u << ' ';
		for (auto& v : adj[u]) {
			if (vis[v]) continue;
			dfs(v);
		}
	};
	dfs(v);
	cout << '\n';
	fill(all(vis), 0LL);
	queue<int> q;
	q.push(v);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		cout << u << ' ';
		for (auto& v : adj[u]) {
			if (!vis[v]) {
				q.push(v);
			}
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}