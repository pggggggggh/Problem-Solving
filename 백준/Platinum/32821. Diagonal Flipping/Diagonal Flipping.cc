#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

int par[50000], sz[50000];

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
	sz[x] += sz[y];
	par[y] = x;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= (n + m) * 5; i++) {
		par[i] = i;
		sz[i] = 1;
	}
	int x;
	vector<pi> e;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int a = i + j - 1, b = i - j + m + n + m - 1;
			cin >> x;
			if (x) e.push_back({ a, b });
			else uni(a, b);
		}
	}
	vector<vector<int>> adj((n + m) * 5);
	for (auto& [x, y] : e) {
		x = find(x);
		y = find(y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<int> color((n + m) * 5, -1);
	vector<int> vec;
	function<int(int)> dfs = [&](int u) {
		vec.push_back(u);
		for (auto& v : adj[u]) {
			if (color[v] == color[u]) return 0;
			if (color[v] == -1) {
				color[v] = 1 - color[u];
				if (!dfs(v)) return 0;
			}
		}
		return 1;
	};
	int res = 0;
	for (int i = 1; i <= 2 * (n + m - 1); i++) {
		if (find(i) != i) continue;
		if (color[i] == -1) {
			color[i] = 0;
			vec.clear();
			if (!dfs(i)) {
				cout << "-1";
				return;
			}
			int allsum = 0, onesum = 0;
			for (auto& v : vec) {
				allsum += sz[v];
				onesum += color[v] * sz[v];
			}
			res += min(onesum, allsum - onesum);
		}
	}
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}