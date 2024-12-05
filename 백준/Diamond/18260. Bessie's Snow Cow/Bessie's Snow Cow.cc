#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int unsigned long long
using namespace std;
using pi = pair<int, int>;

struct lazyseg {
	int sz;
	vector<int> seg, lazy;

	lazyseg(int n)
	{
		sz = 1;
		while (sz < n) sz *= 2;
		seg.resize(2 * sz);
		lazy.resize(2 * sz);
	}

	void propa(int now, int l, int r)
	{
		seg[now] += (r - l + 1) * lazy[now];
		if (l != r) {
			lazy[now * 2] += lazy[now];
			lazy[now * 2 + 1] += lazy[now];
		}
		lazy[now] = 0;
	}

	int query(int x, int y, int now, int l, int r)
	{
		propa(now, l, r);
		if (r < x || y < l) return 0;
		if (x <= l && r <= y) return seg[now];
		int mid = l + r >> 1;
		return query(x, y, now * 2, l, mid) + query(x, y, now * 2 + 1, mid + 1, r);
	}

	void add(int x, int y, int val, int now, int l, int r)
	{
		propa(now, l, r);
		if (r < x || y < l) return;
		if (x <= l && r <= y) {
			lazy[now] += val;
			propa(now, l, r);
			return;
		}
		int mid = l + r >> 1;
		add(x, y, val, now * 2, l, mid);
		add(x, y, val, now * 2 + 1, mid + 1, r);
		seg[now] = seg[now * 2] + seg[now * 2 + 1];
	}
};

struct hslazyseg {
	int sz;
	vector<pi> seg; // {min, num of mins}
	vector<int> lazy;

	pi merge(pi x, pi y)
	{
		if (x.first < y.first) return x;
		else if (x.first > y.first) return y;
		return { x.first, x.second + y.second };
	}

	hslazyseg(int n = 0)
	{
		sz = 1;
		while (sz < n) sz *= 2;
		seg.resize(2 * sz);
		for (int i = sz; i < 2 * sz; i++) seg[i] = { 0, 1 };
		for (int i = sz - 1; i >= 1; i--) seg[i] = merge(seg[i * 2], seg[i * 2 + 1]);
		lazy.resize(2 * sz);
	}

	void propa(int now, int l, int r)
	{
		seg[now].first += lazy[now];
		if (l != r) {
			lazy[now * 2] += lazy[now];
			lazy[now * 2 + 1] += lazy[now];
		}
		lazy[now] = 0;
	}

	pi query(int x, int y, int now, int l, int r)
	{
		propa(now, l, r);
		if (r < x || y < l) return { 1e18, 0 };
		if (x <= l && r <= y) return seg[now];
		int mid = l + r >> 1;
		return merge(query(x, y, now * 2, l, mid), query(x, y, now * 2 + 1, mid + 1, r));
	}

	void add(int x, int y, int val, int now, int l, int r)
	{
		propa(now, l, r);
		if (r < x || y < l) return;
		if (x <= l && r <= y) {
			lazy[now] += val;
			propa(now, l, r);
			return;
		}
		int mid = l + r >> 1;
		add(x, y, val, now * 2, l, mid);
		add(x, y, val, now * 2 + 1, mid + 1, r);
		seg[now] = merge(seg[now * 2], seg[now * 2 + 1]);
	}
};

void solve()
{
	int n, q;
	cin >> n >> q;
	int sq = sqrt(q) / 2;
	vector<vector<int>> adj(n + 1);
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int sn = 0;
	vector<int> in(n + 1), out(n + 1);
	function<void(int, int)> dfs = [&](int u, int p) {
		in[u] = ++sn;
		for (auto& v : adj[u]) {
			if (v == p) continue;
			dfs(v, u);
		}
		out[u] = sn;
	};
	dfs(1, -1);
	vector<vector<array<int, 3>>> qry(q + 1);
	map<int, set<int>> cidx;
	for (int i = 1; i <= q; i++) {
		int x, y, z = 0;
		cin >> x >> y;
		if (x == 1) {
			cin >> z;
			cidx[z].insert(i);
		}
		qry[i].push_back({ x, y, z });
	}
	set<int> bigs, smalls;
	vector<int> ans(q + 1);
	for (auto& [c, st] : cidx) {
		if ((int)st.size() >= sq) bigs.insert(c);
		else smalls.insert(c);
	}

	lazyseg smallseg(n + 1);
	for (int i = 1; i <= q; i++) { // small colors에 대한 답
		for (auto& [op, u, c] : qry[i]) {
			if (op == 0) break;
			if (op == 1) {
				if (bigs.count(c)) continue;
				for (auto& j : cidx[c]) {
					if (j <= i) continue;
					int v = qry[j][0][1];
					// u가 v의 조상이라면 j번째 쿼리는 무시
					if (in[u] <= in[v] && in[v] <= out[u]) qry[j][0][0] = 0;
					// u가 v의 자식이라면 u 롤백 쿼리
					else if (in[v] <= in[u] && in[u] <= out[v]) {
						qry[j].push_back({ 3, u, c });
						break;
					}
				}
				smallseg.add(in[u], out[u], 1, 1, 0, smallseg.sz - 1);
			} else if (op == 2) {
				ans[i] += smallseg.query(in[u], out[u], 1, 0, smallseg.sz - 1);
			} else if (op == 3) {
				smallseg.add(in[u], out[u], -1, 1, 0, smallseg.sz - 1);
			}
		}
	}

	map<int, hslazyseg> bigseg;
	for (int i = 1; i <= q; i++) {
		for (auto& [op, u, c] : qry[i]) {
			if (op == 1) {
				if (smalls.count(c)) continue;
				if (bigseg.find(c) == bigseg.end()) bigseg.insert({ c, hslazyseg(n + 1) });
				bigseg[c].add(in[u], out[u], 1, 1, 0, bigseg[c].sz - 1);
			} else if (op == 2) {
				for (auto& c : bigs) {
					if (bigseg.find(c) == bigseg.end()) bigseg.insert({ c, hslazyseg(n + 1) });
					pi tmp = bigseg[c].query(in[u], out[u], 1, 0, bigseg[c].sz - 1);
					if (tmp.first == 0) ans[i] += (out[u] - in[u] + 1) - tmp.second;
					else ans[i] += (out[u] - in[u] + 1);
				}
			}
		}
	}

	for (int i = 1; i <= q; i++) {
		if (qry[i][0][0] == 2) cout << ans[i] << '\n';
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}