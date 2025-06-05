#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

struct segtree {
	using S = int;
	const S e = 0;

	S op(S a, S b)
	{
		return max(a, b);
	}

	int n, sz;
	vector<S> seg;

	segtree(int n, const vector<S>& v = vector<S>())
	{
		assert(n >= v.size());
		this->n = n;
		sz = 1;
		while (sz < n) sz *= 2;
		seg = vector(2 * sz, e);
		for (int i = 0; i < v.size(); i++) seg[i + sz] = v[i];
		for (int i = sz - 1; i >= 1; i--) seg[i] = op(seg[i * 2], seg[i * 2 + 1]);
	}

	void put(int x, const S& val)
	{
		x += sz;
		seg[x] = val;
		while (x > 1) {
			x /= 2;
			seg[x] = op(seg[x * 2], seg[x * 2 + 1]);
		}
	}

	void add(int x, const S& val)
	{
		x += sz;
		seg[x] = op(seg[x], val);

		while (x > 1) {
			x /= 2;
			seg[x] = op(seg[x * 2], seg[x * 2 + 1]);
		}
	}

	S query(int l, int r)
	{
		S res = e;
		l += sz, r += sz;
		for (; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) res = op(res, seg[l++]);
			if (!(r & 1)) res = op(seg[r--], res);
		}
		return res;
	}
};

void solve()
{
	int n, p, q;
	cin >> n >> p >> q;
	vector<vector<int>> adj(n + 1);
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	queue<int> qq;
	vector<int> past(n + 1), vis(n + 1);
	qq.push(q);
	while (!qq.empty()) {
		int u = qq.front();
		qq.pop();
		vis[u] = 1;
		if (u == p) break;
		for (auto& v : adj[u]) {
			if (vis[v]) continue;
			past[v] = u;
			qq.push(v);
		}
	}
	int cur = p;
	vector<int> path(1); // 1-indexed
	vector<int> inpath(n + 1);
	while (1) {
		inpath[cur] = path.size();
		path.push_back(cur);
		cur = past[cur];
		if (cur == 0) break;
	}
	int m = path.size() - 1;
	function<int(int, int)> dfs = [&](int u, int p) {
		int ret = 0;
		for (auto& v : adj[u]) {
			if (inpath[v] || v == p) continue;
			ret = max(ret, dfs(v, u) + 1);
		}
		return ret;
	};
	segtree ldepth(m + 1), rdepth(m + 1);
	vector<int> depth(m + 1);
	for (int i = 1; i <= m; i++) {
		int sex = dfs(path[i], -1);
		depth[i] = sex;
		ldepth.add(i, sex + i);
		rdepth.add(i, sex + (m - i + 1));
	}
	map<pair<int, int>, int> dp;
	function<int(int, int)> dfs2 = [&](int x, int y) {
		auto it = dp.find(make_pair(x, y));
		if (it != dp.end()) return it->second;
		int ret;
		if (x < y) {
			ret = depth[x] - (rdepth.query(x + 1, y) - (m - y + 1));
			if (x + 1 < y) ret = max(ret, -dfs2(y, x + 1) + 1);
		} else {
			ret = depth[x] - (ldepth.query(y, x - 1) - y);
			if (x - 1 > y) ret = max(ret, -dfs2(y, x - 1) + 1);
		}
		dp[make_pair(x, y)] = ret;
		return ret;
	};
	cout << dfs2(inpath[p], inpath[q]);
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}