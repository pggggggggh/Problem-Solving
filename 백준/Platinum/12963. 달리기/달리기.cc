#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

const int MOD = 1e9 + 7;

void solve()
{
	vector<int> modpow = { 1 };
	for (int i = 1; i <= 3005; i++) modpow.push_back((modpow.back() * 3) % MOD);

	int n, m;
	cin >> n >> m;
	vector<vector<pi>> adj(n);
	int cost = 1;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y, cost);
		adj[y].emplace_back(x, cost);
		cost++;
	}
	cost--;
	int res = 0;
	while (cost) {
		queue<int> q;
		q.push(0);
		vector<int> vis(n);
		vector<pi> from(n);
		from[0] = { -1, -1 };
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			if (u == n - 1) break;
			for (int i = 0; i < adj[u].size(); i++) {
				auto& [v, d] = adj[u][i];
				if (vis[v] || d < cost) continue;
				from[v] = { u, i };
				q.push(v);
			}
		}
		if (vis[n - 1]) {
			res = (res + modpow[cost - 1]) % MOD;
			int cur = n - 1;
			while (1) {
				pi& p = from[cur];
				cur = p.first;
				if (cur == -1) break;
				if (cost == adj[cur][p.second].second) adj[cur][p.second].second = 0;
			}
		}
		cost--;
	}
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}