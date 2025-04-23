#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<vector<int>> adj(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<vector<int>> g(n + 1);
	vector<int> sum(n + 1);
	function<void(int, int)> dfs = [&](int u, int p) {
		sum[u] = a[u];
		for (auto& v : adj[u]) {
			if (v == p) continue;
			g[u].push_back(v);
			dfs(v, u);
			sum[u] += sum[v];
		}
	};
	dfs(1, -1);

	multiset<int> notpar, par;
	for (int i = 1; i <= n; i++) {
		notpar.insert(sum[i]);
	}
	int ans = 1e18;
	function<void(int)> dfs2 = [&](int u) {
		par.insert(sum[u]);
		notpar.erase(notpar.lower_bound(sum[u]));
		for (auto& v : g[u]) {
			dfs2(v);
		}
		par.erase(par.lower_bound(sum[u]));

		// 여기서 계산
		int x, y, z;
		auto it = par.lower_bound((sum[1] + sum[u]) / 2);
		if (it != par.end()) {
			x = sum[u];
			y = *it - sum[u];
			z = sum[1] - *it;
			ans = min(ans, abs(x - y) + abs(y - z) + abs(z - x));
		}
		if (it != par.begin()) {
			it = prev(it);
			x = sum[u];
			y = *it - sum[u];
			z = sum[1] - *it;
			ans = min(ans, abs(x - y) + abs(y - z) + abs(z - x));
		}
		it = notpar.lower_bound((sum[1] - sum[u]) / 2);
		if (it != notpar.end()) {
			x = sum[u];
			y = *it;
			z = sum[1] - *it - sum[u];
			ans = min(ans, abs(x - y) + abs(y - z) + abs(z - x));
		}
		if (it != notpar.begin()) {
			it = prev(it);
			x = sum[u];
			y = *it;
			z = sum[1] - *it - sum[u];
			ans = min(ans, abs(x - y) + abs(y - z) + abs(z - x));
		}
		// notpar.insert(sum[u]);
	};
	dfs2(1);
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}