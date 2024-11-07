#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

int n;

void solve()
{
	vector<vector<pi>> adj(n), g(n);
	for (int i = 0; i < n - 1; i++) {
		int s, e, x;
		cin >> s >> e >> x;
		adj[s].emplace_back(e, x);
		adj[e].emplace_back(s, x);
	}
	vector<int> sub(n, 1), dist1(n);
	function<void(int, int)> dfs = [&](int u, int p) {
		for (auto& [v, d] : adj[u]) {
			if (v == p) continue;
			g[u].emplace_back(v, d);
			dist1[v] = dist1[u] + d;
			dfs(v, u);
			sub[u] += sub[v];
		}
	};
	dfs(0, -1);
	vector<int> ans(n);
	ans[0] = accumulate(all(dist1), 0LL);
	function<void(int)> reroot = [&](int u) {
		for (auto& [v, d] : g[u]) {
			ans[v] = ans[u] + (n - 2 * sub[v]) * d;
			reroot(v);
		}
	};
	reroot(0);
	cout << *min_element(all(ans)) << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		cin >> n;
		if (!n) break;
		solve();
	}
}