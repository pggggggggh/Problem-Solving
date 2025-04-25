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
	vector<vector<pi>> adj(n + 1);

	for (int i = 0; i < m; i++) {
		int s, e;
		char x;
		cin >> s >> e >> x;
		if (x == 'B') {
			adj[s].emplace_back(e, 0);
			adj[e].emplace_back(s, 0);
		} else {
			adj[s].emplace_back(e, 1);
			adj[e].emplace_back(s, 1);
		}
	}

	vector<vector<int>> vis(n + 1, vector<int>(2)), fin(n + 1, vector<int>(2));
	int cycle = 0;
	function<void(int, int)> fuck = [&](int u, int c) {
		vis[u][c] = 1;
		for (auto& [v, color] : adj[u]) {
			if (color + c == 1) {
				if (!vis[v][color]) fuck(v, color);
				else if (!fin[v][color]) cycle = 1;
			}
		}
		fin[u][c] = 1;
	};
	for (int i = 1; i <= n; i++) {
		if (!vis[i][0]) fuck(i, 0);
	}
	if (cycle) {
		cout << "-1\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		for (int c = 0; c <= 1; c++) vis[i][c] = fin[i][c] = 0;
	}
	cycle = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i][1]) fuck(i, 1);
	}
	if (cycle) {
		cout << "-1\n";
		return;
	}

	vector<vector<int>> dp(n + 1, vector<int>(2, -1));
	function<int(int, int)> dfs = [&](int u, int c) { // 이전에 밟은 색
		int& ret = dp[u][c];
		if (ret != -1) return ret;
		ret = 0;
		for (auto& [v, color] : adj[u]) {
			if (color + c == 1) {
				ret = max(ret, dfs(v, color) + 1);
			}
		}
		return ret;
	};
	int ans0 = 0, ans1 = 0;
	for (int i = 1; i <= n; i++) {
		ans0 = max(ans0, dfs(i, 0)); // RBRB
	}
	for (int i = 1; i <= n; i++) {
		for (int c = 0; c <= 1; c++) dp[i][c] = -1;
	}
	for (int i = 1; i <= n; i++) {
		ans1 = max(ans1, dfs(i, 1)); // BRBR
	}
	if (ans0 < ans1) {
		for (int i = 0; i < ans0 + 1; i++) {
			cout << (i % 2 ? 'B' : 'R');
		}
	} else {
		for (int i = 0; i < ans1 + 1; i++) {
			cout << (i % 2 ? 'R' : 'B');
		}
	}
	cout << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) solve();
}