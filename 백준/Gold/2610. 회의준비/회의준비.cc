#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

struct union_find {
	vector<int> par;
	int n;

	union_find(int n)
	{
		this->n = n;
		for (int i = 0; i < n; i++) par.push_back(i);
	}

	int find(int x)
	{
		if (x == par[x]) return x;
		return par[x] = find(par[x]);
	}

	void uni(int x, int y)
	{
		x = find(x), y = find(y);
		if (x == y) return;
		par[y] = x;
	}
};

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	union_find uf(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		uf.uni(x, y);
	}

	function<int(int)> maxdist = [&](int s) {
		queue<int> q;
		vector<int> vis(n + 1);
		vector<int> dist(n + 1, 1e18);
		q.push(s);
		vis[s] = 1;
		dist[s] = 0;
		while (!q.empty()) {
			auto u = q.front();
			q.pop();
			for (auto& v : adj[u]) {
				if (vis[v]) continue;
				vis[v] = 1;
				dist[v] = min(dist[v], dist[u] + 1);
				q.push(v);
			}
		}
		int ret = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] != 1e18) ret = max(ret, dist[i]);
		}
		return ret;
	};

	vector<pi> parmin(n + 1, { 1e18, -1 });
	for (int i = 1; i <= n; i++) {
		parmin[uf.find(i)] = min((pi) { maxdist(i), i }, parmin[uf.find(i)]);
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (parmin[i].second != -1)
			ans.push_back(parmin[i].second);
	}
	sort(all(ans));
	cout << ans.size() << '\n';
	for (auto& x : ans) cout << x << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}