#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
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
		seg.resize(2 * sz);
	}

	void update(int x, int val)
	{
		x += sz;
		seg[x] = val;
		while (x /= 2) seg[x] = seg[2 * x] + seg[2 * x + 1];
	}

	int query(int x, int y)
	{
		int res = 0;
		x += sz, y += sz;
		while (x <= y) {
			if (x & 1) res += seg[x++];
			if (~y & 1) res += seg[y--];
			x >>= 1, y >>= 1;
		}
		return res;
	}
};

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1), p(n + 1), sum(n + 1);
	vector<pi> edges;
	vector<array<int, 3>> queries(q);
	vector<vector<int>> g(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		g[p[i]].push_back(i);
		edges.emplace_back(p[i], i);
	}
	sort(all(edges));
	function<void(int)> dfs = [&](int u) {
		sum[u] = a[u];
		for (auto& v : g[u]) {
			dfs(v);
			sum[u] += sum[v];
		}
	};
	dfs(1);
	for (int i = 0; i < q; i++) {
		cin >> queries[i][0] >> queries[i][1];
		queries[i][2] = i;
	}
	sort(all(queries));
	segtree seg(n + 1);
	vector<int> ans(q);
	int idx = 0;
	seg.update(1, sum[1]);
	for (auto& [s, e, x] : queries) {
		while (idx < n - 1 && edges[idx].first < s) {
			seg.update(edges[idx].second, sum[edges[idx].second]);
			idx++;
		}
		ans[x] = seg.query(s, e);
	}
	for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}