#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	vector<vector<int>> sccs;
	vector<int> id(n + 1), low(n + 1), fin(n + 1);
	vector<int> stk;
	int dfn = 0;
	function<int(int)> dfs = [&](int u) {
		stk.push_back(u);
		id[u] = ++dfn;
		low[u] = dfn;
		for (auto& v : adj[u]) {
			if (!low[v]) low[u] = min(low[u], dfs(v));
			else if (!fin[v]) low[u] = min(low[u], low[v]);
		}
		if (low[u] == id[u]) {
			vector<int> scc;
			while (1) {
				int tmp = stk.back();
				fin[tmp] = 1;
				scc.push_back(tmp);
				stk.pop_back();
				if (tmp == u) break;
			}
			sort(all(scc));
			sccs.push_back(scc);
		}
		return low[u];
	};
	for (int i = 1; i <= n; i++)
		if (!low[i]) dfs(i);
	sort(all(sccs));
	cout << sccs.size() << '\n';
	for (auto& scc : sccs) {
		for (auto& x : scc) cout << x << ' ';
		cout << "-1\n";
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}