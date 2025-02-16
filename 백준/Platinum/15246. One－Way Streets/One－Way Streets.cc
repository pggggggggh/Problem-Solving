#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

struct biconnected {
	int n;
	vector<vector<int>> adj;

	biconnected(int n)
	{
		this->n = n;
		adj.resize(n);
	}

	void add_edge(int from, int to)
	{ // undirected
		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	vector<set<int>> get_bcc()
	{ // multiple edges not considered
		vector<int> dfn(n, -1);
		vector<set<int>> bn(n);
		int cnt = 0, bcnt = 0;
		stack<pi> stk;
		function<int(int, int)> dfs = [&](int v, int p) {
			dfn[v] = ++cnt;
			int res = dfn[v];
			for (auto& u : adj[v]) {
				if (u == p) continue;
				if (dfn[v] > dfn[u]) stk.push({ v, u });
				if (dfn[u] != -1) res = min(res, dfn[u]);
				else {
					int low = dfs(u, v);
					res = min(res, low);
					if (low >= dfn[v]) {
						while (1) {
							auto [vv, uu] = stk.top();
							stk.pop();
							bn[vv].insert(bcnt);
							bn[uu].insert(bcnt);
							if (vv == v && uu == u) break;
						}
						bcnt++;
					}
				}
			}
			return res;
		};
		for (int i = 0; i < n; i++)
			if (dfn[i] == -1) dfs(i, 0);
		return bn;
	}

	vector<int> get_articulation_points()
	{
		vector<set<int>> bn = get_bcc();
		vector<int> res;
		for (int i = 0; i < n; i++)
			if (bn[i].size() > 1) res.push_back(i);
		return res;
	}

	set<pi> get_bridges()
	{
		vector<set<int>> bn = get_bcc();
		vector<vector<int>> cmp(n);
		set<pi> res;
		int cn = 0;
		for (int i = 0; i < n; i++) {
			for (auto& x : bn[i]) {
				cn = max(cn, x + 1);
				cmp[x].push_back(i);
			}
		}
		for (int i = 0; i < cn; i++) {
			if (cmp[i].size() == 2) res.insert(pair(min(cmp[i][0], cmp[i][1]), max(cmp[i][0], cmp[i][1])));
		}
		return res;
	}
};

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

struct lazyseg {
	using S = int;
	using L = int;
	const S seg_e = 0; // identity of seg_op
	const L lazy_e = 0; // identity of lazy_op

	S seg_op(S a, S b)
	{ // combine two nodes
		return a + b;
	}

	L lazy_op(L a, L b)
	{ // combine two lazy values
		return a + b;
	}

	void apply_lazy(S& s, L l, int len)
	{
		s += l * len;
	}

	int n, sz;
	vector<S> seg;
	vector<L> lazy;

	lazyseg(int n, const vector<S>& v = vector<S>())
	{
		assert(n >= v.size());
		this->n = n;
		sz = 1;
		while (sz < n) sz *= 2;
		seg = vector(2 * sz, seg_e);
		lazy = vector(2 * sz, lazy_e);
		for (int i = 0; i < v.size(); i++) seg[i + sz] = v[i];
		for (int i = sz - 1; i >= 1; i--) seg[i] = seg_op(seg[i * 2], seg[i * 2 + 1]);
	}

	void propa(int node, int l, int r)
	{
		if (lazy[node] == lazy_e) return;
		apply_lazy(seg[node], lazy[node], r - l + 1);
		if (l != r) {
			lazy[node * 2] = lazy_op(lazy[node * 2], lazy[node]);
			lazy[node * 2 + 1] = lazy_op(lazy[node * 2 + 1], lazy[node]);
		}
		lazy[node] = lazy_e;
	}

	void put(int x, S val, int node, int l, int r)
	{
		propa(node, l, r);
		if (l == r) {
			seg[node] = val;
			return;
		}
		int mid = l + r >> 1;
		if (x <= mid) put(x, val, node * 2, l, mid);
		else put(x, val, node * 2 + 1, mid + 1, r);
		seg[node] = seg_op(seg[node * 2], seg[node * 2 + 1]);
	}

	void put(int x, S val)
	{
		put(x, val, 1, 0, sz - 1);
	}

	void add(int x, int y, S val, int node, int l, int r)
	{
		propa(node, l, r);
		if (r < x || y < l) return;
		if (x <= l && r <= y) {
			lazy[node] = lazy_op(lazy[node], val);
			propa(node, l, r);
			return;
		}
		int mid = l + r >> 1;
		add(x, y, val, node * 2, l, mid);
		add(x, y, val, node * 2 + 1, mid + 1, r);
		seg[node] = seg_op(seg[node * 2], seg[node * 2 + 1]);
	}

	void add(int x, int y, S val)
	{
		add(x, y, val, 1, 0, sz - 1);
	}

	S query(int x, int y, int node, int l, int r)
	{
		propa(node, l, r);
		if (r < x || y < l) return seg_e;
		if (x <= l && r <= y) return seg[node];
		int mid = l + r >> 1;
		return seg_op(query(x, y, node * 2, l, mid), query(x, y, node * 2 + 1, mid + 1, r));
	}

	S query(int x, int y)
	{
		return query(x, y, 1, 0, sz - 1);
	}
};

struct heavy_light_decomposition {
	int n;
	vector<vector<int>> adj, g; // adj must be bidirectional
	vector<int> par, depth, sz, top, pos, vis;
	int dfn = 0;
	lazyseg seg;

	heavy_light_decomposition(const vector<vector<int>>& _adj, vector<int>& roots)
	    : n(_adj.size()), adj(_adj), g(n), par(n), depth(n), sz(n), top(n), pos(n), vis(n), seg(n)
	{
		for (auto& root : roots) {
			par[root] = -1;
			top[root] = root;
			dfs_tree(root);
			dfs_size(root);
			dfs_hld(root);
		}
	}

	void dfs_tree(int v)
	{
		vis[v] = 1;
		for (auto& u : adj[v]) {
			if (vis[u]) continue;
			g[v].push_back(u);
			dfs_tree(u);
		}
	}

	void dfs_size(int v)
	{
		sz[v] = 1;
		for (auto& u : g[v]) {
			depth[u] = depth[v] + 1;
			par[u] = v;
			dfs_size(u);
			sz[v] += sz[u];
			if (sz[u] > sz[g[v][0]]) swap(u, g[v][0]);
		}
	}

	void dfs_hld(int v)
	{
		pos[v] = dfn++; // 0-indexed
		for (auto& u : g[v]) {
			top[u] = u == g[v][0] ? top[v] : u;
			dfs_hld(u);
		}
	}

	void update(int v, int w)
	{ // vertex
		seg.put(pos[v], w);
	}

	int query(int a, int b)
	{
		int res = seg.seg_e;
		while (top[a] != top[b]) {
			if (depth[top[a]] < depth[top[b]]) swap(a, b);
			int st = top[a];
			res = seg.seg_op(res, seg.query(pos[st], pos[a]));
			a = par[st];
		}
		if (depth[a] > depth[b]) swap(a, b);
		res = seg.seg_op(res, seg.query(pos[a] + 1, pos[b]));
		return res;
	}

	void add(int a, int b, int w)
	{
		while (top[a] != top[b]) {
			if (depth[top[a]] < depth[top[b]]) swap(a, b);
			int st = top[a];
			seg.add(pos[st], pos[a], w);
			a = par[st];
		}
		if (depth[a] > depth[b]) swap(a, b);
		seg.add(pos[a] + 1, pos[b], w);
	}
};

void solve()
{
	int n, m, p;
	cin >> n >> m;
	biconnected bcc(n + 1);
	map<pi, int> edge_idx;
	map<pi, int> edge_cnt;
	vector<pi> edges, orig_edges;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		orig_edges.push_back({ s, e });
		if (s > e) swap(s, e);
		bcc.add_edge(s, e);
		edge_cnt[{ s, e }]++;
		edges.push_back({ s, e });
	}
	union_find uf(n + 1);
	set<pi> bridges = bcc.get_bridges();
	set<pi> tmp;
	for (auto& [s, e] : bridges) {
		if (edge_cnt[{ s, e }] > 1) {
		} else tmp.insert({ s, e });
	}
	bridges = tmp;

	vector<vector<int>> adj(n + 1);
	union_find ufc(n + 1);
	for (auto& [s, e] : edges)
		if (!bridges.count({ s, e })) uf.uni(s, e);
	for (int i = 0; i < m; i++) {
		auto& [s, e] = edges[i];
		int x = uf.find(s), y = uf.find(e);
		ufc.uni(x, y);

		if (!bridges.count({ s, e })) continue;
		if (uf.find(s) == uf.find(e)) continue;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	vector<vector<int>> par(n + 1, vector<int>(25));
	vector<int> dep(n + 1);
	vector<int> ans(m, 0);

	function<void(int, int)> dfs = [&](int u, int p) {
		for (auto& v : adj[u]) {
			if (v == p) continue;
			par[v][0] = u;
			dep[v] = dep[u] + 1;
			dfs(v, u);
		}
	};

	int ptr = 0;
	vector<int> roots;
	for (int i = 1; i <= n; i++) {
		if (uf.find(i) == i && ufc.find(i) == i) {
			dfs(i, -1);
			roots.push_back(i);
		}
	}
	for (int i = 1; i <= 20; i++) {
		for (int u = 1; u <= n; u++) {
			if (uf.find(u) != u) continue;
			par[u][i] = par[par[u][i - 1]][i - 1];
		}
	}
	function<int(int, int)> lca = [&](int u, int v) {
		if (dep[u] < dep[v]) swap(u, v);
		int diff = dep[u] - dep[v];
		for (int i = 20; i >= 0; i--) {
			if ((diff >> i) & 1) u = par[u][i];
		}
		if (u == v) return u;
		for (int i = 20; i >= 0; i--) {
			if (par[u][i] != par[v][i]) {
				u = par[u][i], v = par[v][i];
			}
		}
		return par[u][0];
	};
	heavy_light_decomposition hld(adj, roots);

	cin >> p;
	for (int i = 0; i < p; i++) {
		int x, y;
		cin >> x >> y;
		x = uf.find(x), y = uf.find(y);
		int l = lca(x, y);
		hld.add(x, l, 1);
		hld.add(y, l, -1);
	}

	for (int i = 0; i < m; i++) {
		auto [x, y] = orig_edges[i];
		x = uf.find(x), y = uf.find(y);
		int swapped = 0;
		if (dep[x] < dep[y]) {
			swap(x, y);
			swapped = 1;
		}
		int res = hld.query(uf.find(x), uf.find(y));
		if (res > 0) {
			if (!swapped) ans[i] = 1;
			else ans[i] = -1;
		}
		if (res < 0) {
			if (!swapped) ans[i] = -1;
			else ans[i] = 1;
		}
	}

	for (int i = 0; i < m; i++) cout << (ans[i] == 0 ? 'B' : (ans[i] == 1 ? 'R' : 'L'));
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}