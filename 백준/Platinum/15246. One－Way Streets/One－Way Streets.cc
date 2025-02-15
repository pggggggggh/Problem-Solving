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

	vector<vector<array<int, 3>>> adj(n + 1); // bcc adj, -1이면 L, 1이면 R
	for (auto& [s, e] : edges)
		if (!bridges.count({ s, e })) uf.uni(s, e);
	for (int i = 0; i < m; i++) {
		auto& [s, e] = edges[i];
		if (!bridges.count({ s, e })) continue;
		if (uf.find(s) == uf.find(e)) continue;
		int x = uf.find(s), y = uf.find(e);
		if (orig_edges[i].first == s) {
			adj[x].push_back({ y, i, 1 });
			adj[y].push_back({ x, i, -1 });
		} else {
			adj[x].push_back({ y, i, -1 });
			adj[y].push_back({ x, i, 1 });
		}
	}

	cin >> p;
	vector<char> ans(m, 'B');
	for (int i = 0; i < p; i++) {
		int x, y;
		cin >> x >> y;
		x = uf.find(x), y = uf.find(y);

		queue<int> q;
		vector<array<int, 3>> prev(n + 1, { -1, -1, -1 });
		vector<int> vis(n + 1);
		q.emplace(x);
		while (!q.empty()) {
			auto u = q.front();
			q.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			if (u == y) break;

			for (auto& [v, idx, d] : adj[u]) {
				if (vis[v]) continue;
				prev[v] = { u, idx, d };
				q.emplace(v);
			}
		}

		int cur = y;
		while (1) {
			auto [u, idx, d] = prev[cur];
			if (u == -1) break;
			if (d == -1) ans[idx] = 'L';
			else ans[idx] = 'R';
			cur = u;
		}
	}

	for (int i = 0; i < m; i++) {
		if (!bridges.count({ edges[i].first, edges[i].second })) ans[i] = 'B';
	}
	for (int i = 0; i < m; i++) cout << ans[i];
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}