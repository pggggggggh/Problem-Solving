#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

map<pi, int> can;

void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		int x, y;
		cin >> x >> y;
		can[{ x, y }] = i;
	}
	int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
	vector<vector<int>> adj(2 * n);
	for (auto& [k, v] : can) {
		auto& [x, y] = k;
		if ((x & 1) ^ (y & 1)) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (can.find({ nx, ny }) != can.end()) {
				if (can[{ nx, ny }] != (v ^ 1)) {
					adj[v].push_back(can[{ nx, ny }]);
				}
			}
		}
	}
	vector<int> r(2 * n, -1), l(2 * n, -1);
	vector<int> vis(2 * n);
	function<int(int)> dfs = [&](int u) {
		vis[u] = 1;
		for (auto& v : adj[u]) {
			if (l[v] == -1 || (!vis[l[v]] && dfs(l[v]))) {
				r[u] = v;
				l[v] = u;
				return 1;
			}
		}
		return 0;
	};
	for (int i = 0; i < 2 * n; i++) {
		if (r[i] == -1) {
			fill(all(vis), 0);
			dfs(i);
		}
	}
	vector<int> ans(2 * n, -1);
	int ptr = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (r[i] != -1 && ans[i] == -1) {
			ans[i] = ans[r[i]] = ptr++;
		}
	}
	if (ptr == n) {
		for (int i = 0; i < n; i++) {
			cout << ans[2 * i] << ' ' << ans[2 * i + 1] << '\n';
		}
	} else cout << "impossible";
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}