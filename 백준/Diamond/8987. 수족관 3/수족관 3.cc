#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
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
		seg.resize(2 * sz, 1e18);
	}

	void update(int x, int val)
	{
		x += sz;
		seg[x] = min(seg[x], val);
		while (1) {
			x /= 2;
			if (x == 0) return;
			seg[x] = min(seg[x * 2], seg[x * 2 + 1]);
		}
	}

	int query(int x, int y)
	{
		int ret = 1e18;
		x += sz, y += sz;
		while (x <= y) {
			if (x & 1) ret = min(ret, seg[x++]);
			if (~(y & 1)) ret = min(ret, seg[y--]);
			x >>= 1, y >>= 1;
		}
		return ret;
	}
};

struct lazyseg {
	const pi e = { 0, 0 };

	pi op(pi x, pi y)
	{
		if (x.first > y.first) return x;
		return y;
	}

	int sz;
	vector<pi> seg;
	vector<int> lazy;

	lazyseg(int n)
	{
		sz = 1;
		while (sz < n) sz *= 2;
		seg.resize(2 * sz, e);
		lazy.resize(2 * sz, 0);
		for (int i = sz; i < 2 * sz; i++) seg[i].second = i - sz;
		for (int i = sz - 1; i >= 1; i--) seg[i] = op(seg[i * 2], seg[i * 2 + 1]);
	}

	void propa(int node, int l, int r)
	{
		seg[node].first += lazy[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	void update(int x, int y, int val, int node, int l, int r)
	{
		if (r < x || y < l) return;
		propa(node, l, r);
		if (x <= l && r <= y) {
			lazy[node] += val;
			propa(node, l, r);
			return;
		}
		int mid = l + r >> 1;
		update(x, y, val, node * 2, l, mid);
		update(x, y, val, node * 2 + 1, mid + 1, r);
		seg[node] = op(seg[node * 2], seg[node * 2 + 1]);
	}

	pi query(int x, int y, int node, int l, int r)
	{
		if (r < x || y < l) return e;
		propa(node, l, r);
		if (x <= l && r <= y) return seg[node];
		int mid = l + r >> 1;
		return op(query(x, y, node * 2, l, mid), query(x, y, node * 2 + 1, mid + 1, r));
	}
};

void solve()
{
	int n, m;
	cin >> n;
	map<int, set<pi>> mp;
	vector<pi> a(n);
	vector<int> coord;
	segtree seg(500005);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		coord.push_back(a[i].first);
		coord.push_back(a[i].second);
	}
	cin >> m;

	sort(all(coord));
	coord.erase(unique(all(coord)), coord.end());
	for (int i = 0; i < n; i++) {
		a[i].first = lower_bound(all(coord), a[i].first) - coord.begin();
		a[i].second = lower_bound(all(coord), a[i].second) - coord.begin();
	}
	for (int i = 1; i < n; i += 2) {
		mp[a[i].second].insert({ a[i].first, a[i + 1].first });
		seg.update(a[i].first, a[i].second);
	}
	int nodes = 0;
	vector<int> waters(300005);
	vector<int> p(300005);
	vector<vector<int>> adj(300005);
	function<void(int, int, int, int)> dfs = [&](int s, int e, int dep, int par) {
		if (s == e) return;

		int u = ++nodes;
		int mn = seg.query(s, e - 1);
		int water = (coord[e] - coord[s]) * (coord[mn] - coord[dep]);
		vector<pi> div;
		auto it = mp[mn].lower_bound({ s, -1e18 });
		while (it != mp[mn].end() && it->first < e) {
			div.push_back(*it);
			it++;
		}
		if (div.empty()) {
		} else {
			dfs(s, div[0].first, mn, u);
			for (int i = 1; i < div.size(); i++) {
				dfs(div[i - 1].second, div[i].first, mn, u);
			}
			dfs(div.back().second, e, mn, u);
		}

		waters[u] = water;
		p[u] = par;
		adj[par].push_back(u);
	};
	dfs(0, a.back().first, 0, 0);
	int cur = 0;
	vector<int> gab(nodes + 1);
	vector<int> in(nodes + 1), out(nodes + 1);
	vector<int> in_to_node(nodes + 1);
	int dfn = 0;
	function<int(int)> dfs2 = [&](int u) {
		in[u] = ++dfn;
		in_to_node[dfn] = u;
		cur += waters[u];
		gab[u] = cur;
		for (auto& v : adj[u]) {
			dfs2(v);
		}
		cur -= waters[u];
		out[u] = dfn;
		return 0;
	};
	dfs2(1);
	lazyseg ett(nodes + 5);
	for (int i = 1; i <= nodes; i++) {
		ett.update(in[i], in[i], gab[i], 1, 0, ett.sz - 1);
	}

	int ans = 0;
	while (m--) {
		pi sex = ett.query(1, nodes, 1, 0, ett.sz - 1);
		ans += sex.first;
		int cur = in_to_node[sex.second];

		while (waters[cur] != 0) {
			// cout << cur << ':' << in[cur] << ' ' << out[cur] << ' ' << waters[cur] << '\n';
			ett.update(in[cur], out[cur], -waters[cur], 1, 0, ett.sz - 1);
			gab[cur] = 0;
			cur = p[cur];
		}
	}

	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}