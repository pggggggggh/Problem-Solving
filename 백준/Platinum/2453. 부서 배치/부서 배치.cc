#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

struct union_find {
	int n;
	vector<int> par, sz;

	union_find(int n)
	    : n(n)
	{
		par.resize(n);
		sz.resize(n);
		for (int i = 0; i < n; i++) {
			par[i] = i;
			sz[i] = 1;
		}
	}

	int find(int x)
	{
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}

	void uni(int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x == y) return;
		par[y] = x;
		sz[x] += sz[y];
	}
};

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<pi> edges;
	union_find uf(n + 1);
	for (int i = 0; i < m; i++) {
		int x, s, e;
		cin >> x >> s >> e;
		if (x == -1) edges.emplace_back(s, e);
		else uf.uni(s, e);
	}
	vector<vector<int>> adj(n + 1);
	for (auto& [s, e] : edges) {
		int u = uf.find(s), v = uf.find(e);
		if (u == v) {
			cout << "-1\n";
			return;
		}
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> col(n + 1, -1);
	int zero, one;
	function<bool(int, int)> dfs = [&](int u, int color) {
		col[u] = color;
		if (color == 0) zero += uf.sz[u];
		else one += uf.sz[u];
		for (auto& v : adj[u]) {
			if (col[v] == color) return false;
			if (col[v] == -1) {
				if (!dfs(v, color ^ 1)) return false;
			}
		}
		return true;
	};
	vector<int> zeros, ones;
	for (int i = 1; i <= n; i++) {
		if (uf.find(i) != i) continue;
		if (col[i] != -1) continue;
		zero = one = 0;
		if (!dfs(i, 0)) {
			cout << "-1\n";
			return;
		}
		zeros.push_back(zero);
		ones.push_back(one);
	}

	vector<int> dp(20005);
	dp[10000] = 1;
	for (int i = 0; i < zeros.size(); i++) {
		int cha = zeros[i] - ones[i];
		vector<int> dp2(20005);
		for (int j = 0; j <= 20000; j++) {
			if (!dp[j]) continue;
			if (j - cha >= 0) dp2[j - cha] = 1;
			if (j + cha <= 20000) dp2[j + cha] = 1;
		}
		dp = dp2;
	}
	int ans = 1e18;
	for (int i = 0; i <= 20000; i++) {
		if (dp[i]) ans = min(ans, abs(i - 10000));
	}
	cout << ans << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 5;
	while (t--) solve();
}