#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<int> sub(n + 1, 1), par(n + 1);
	vector<vector<int>> g(n + 1);
	function<void(int, int)> dfs = [&](int u, int p) {
		for (auto& v : adj[u]) {
			if (v == p) continue;
			g[u].push_back(v);
			par[v] = u;
			dfs(v, u);
			sub[u] += sub[v];
		}
	};
	int a, b, c;
	cin >> a >> b >> c;
	dfs(c, -1);
	set<int> st;
	while (a != c) {
		st.insert(a);
		a = par[a];
	}
	while (b != c) {
		st.insert(b);
		b = par[b];
	}
	int res = 1;
	for (auto& x : g[c]) {
		if (!st.count(x)) res += sub[x];
	}
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}