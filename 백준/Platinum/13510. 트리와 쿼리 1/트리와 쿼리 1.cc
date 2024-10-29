#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

struct segtree {
	int sz;
	vector<int> seg;

	segtree(int n)
	{
		sz = 1;
		while (sz < n) sz *= 2;
		seg.resize(2 * sz, 0);
	}

	void update(int x, int val)
	{
		x += sz;
		seg[x] = val;
		x /= 2;
		while (x) {
			seg[x] = max(seg[x * 2], seg[x * 2 + 1]);
			x /= 2;
		}
	}

	int query(int l, int r)
	{
		l += sz, r += sz;
		int ret = 0;
		while (l <= r) {
			if (l & 1) ret = max(ret, seg[l++]);
			if (~r & 1) ret = max(ret, seg[r--]);
			l >>= 1, r >>= 1;
		}
		return ret;
	}
};

struct HLD {
	vector<vector<int>> adj;
	vector<vector<int>> g;
	vector<int> sz, dep, par, top, in;
	segtree seg;

	HLD(int n)
	    : adj(n + 1)
	    , g(n + 1)
	    , sz(n + 1)
	    , dep(n + 1)
	    , par(n + 1)
	    , top(n + 1)
	    , in(n + 1)
	    , seg(n + 1)
	{
	}

	void add_edge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void update_edge(int u, int v, int w)
	{
		if (dep[u] < dep[v]) swap(u, v);
		seg.update(in[u], w);
	}

	void dfs_tree(int u, int p)
	{
		for (auto& v : adj[u]) {
			if (v == p) continue;
			g[u].push_back(v);
			par[v] = u;
			dfs_tree(v, u);
		}
	}

	void dfs_heavy(int u)
	{
		sz[u] = 1;
		for (auto& v : g[u]) {
			dep[v] = dep[u] + 1;
			dfs_heavy(v);
			sz[u] += sz[v];
			if (sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
		}
	}

	int dfn = 0;
	void dfs_hld(int u)
	{
		in[u] = ++dfn;
		for (auto& v : g[u]) {
			if (v == g[u][0]) top[v] = top[u];
			else top[v] = v;
			dfs_hld(v);
		}
	}

	int query(int u, int v)
	{
		int ret = 0;
		while (top[u] != top[v]) {
			if (dep[top[u]] < dep[top[v]]) swap(u, v);
			int t = top[u];
			ret = max(ret, seg.query(in[t], in[u]));
			u = par[t];
		}
		if (dep[u] > dep[v]) swap(u, v);
		ret = max(ret, seg.query(in[u] + 1, in[v]));
		return ret;
	}
};

void solve()
{
	int n;
	vector<array<int, 3>> edges;
	cin >> n;
	HLD hld(n);
	for (int i = 0; i < n - 1; i++) {
		int s, e, x;
		cin >> s >> e >> x;
		hld.add_edge(s, e);
		edges.push_back({ s, e, x });
	}
	hld.dfs_tree(1, -1);
	hld.dfs_heavy(1);
	hld.dfs_hld(1);
	for (int i = 0; i < n - 1; i++) hld.update_edge(edges[i][0], edges[i][1], edges[i][2]);
	int q;
	cin >> q;
	while (q--) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 1) hld.update_edge(edges[y - 1][0], edges[y - 1][1], z);
		else cout << hld.query(y, z) << '\n';
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}