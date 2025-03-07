#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	vector<int> l(n + 1), r(n + 1);
	vector<int> vis(n + 1);
	function<int(int)> dfs = [&](int u) {
		vis[u] = 1;
		for (auto& v : adj[u]) {
			if (l[v] == 0) {
				r[u] = v;
				l[v] = u;
				return 1;
			}
			if (!vis[l[v]] && dfs(l[v])) {
				r[u] = v;
				l[v] = u;
				return 1;
			}
		}
		return 0;
	};
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (r[i] == 0) {
			fill(all(vis), 0);
			dfs(i);
		}
	}
	for (int i = 1; i <= n; i++)
		if (r[i] != 0) ans++;
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}