#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<vector<pi>> adj(n + 1);
	vector<array<int, 3>> edges;
	for (int i = 1; i < n; i++) {
		int s, e, x;
		cin >> s >> e >> x;
		adj[s].push_back({ e, x });
		adj[e].push_back({ s, x });
		edges.push_back({ s, e, x });
	}
	vector<int> dist(n + 1);
	function<void(int)> getdist = [&](int s) {
		dist[s] = 0;
		queue<int> q;
		vector<int> vis(n + 1);
		q.push(s);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			for (auto& [v, d] : adj[u]) {
				if (vis[v]) continue;
				dist[v] = dist[u] + d;
				q.push(v);
			}
		}
	};
	getdist(1);
	vector<int> dist1 = dist;
	int du = max_element(all(dist1)) - dist1.begin();
	getdist(du);
	vector<int> distu = dist;
	int dv = max_element(all(distu)) - distu.begin();
	getdist(dv);
	vector<int> distv = dist;

	int len_d = distu[dv];
	vector<int> didx(n + 1, -1);
	vector<int> diam;
	vector<int> height(n + 1), subd(n + 1);
	int cur = du;
	int cnt = 0;

	function<void(int, int)> treedp = [&](int u, int p) {
		int mx = 0, mx2 = 0;
		for (auto& [v, d] : adj[u]) {
			if (v == p) continue;
			if (didx[v] != -1) continue;
			treedp(v, u);

			if (height[v] + d > mx) {
				mx2 = mx;
				mx = height[v] + d;
			} else if (height[v] + d > mx2) {
				mx2 = height[v] + d;
			}
			subd[u] = max(subd[u], subd[v]);
		}
		height[u] = mx;
		subd[u] = max(subd[u], mx + mx2);
	};
	while (1) {
		didx[cur] = diam.size();
		diam.push_back(cur);
		if (cur == dv) break;
		for (auto& [nxt, d] : adj[cur]) {
			if (distu[cur] + d + distv[nxt] == len_d) {
				cur = nxt;
				break;
			}
		}
	}
	for (auto& u : diam) treedp(u, -1);
	int dn = diam.size();
	vector<int> prefixmx(dn + 1), suffixmx(dn + 1);
	for (int i = 0; i < dn; i++) {
		if (i) prefixmx[i] = prefixmx[i - 1];
		prefixmx[i] = max(prefixmx[i], distu[diam[i]] + height[diam[i]]);
	}
	for (int i = dn - 1; i >= 0; i--) {
		suffixmx[i] = suffixmx[i + 1];
		suffixmx[i] = max(suffixmx[i], distv[diam[i]] + height[diam[i]]);
	}

	int ans = 0;
	for (auto [s, e, x] : edges) {
		int cur;
		if (didx[s] != -1 && didx[e] != -1) {
			if (didx[s] > didx[e]) swap(s, e);
			cur = prefixmx[didx[s]] + suffixmx[didx[e]] + x;
		} else {
			if (height[s] < height[e]) swap(s, e);
			cur = len_d + subd[e] + x;
		}
		ans = max(ans, cur);
	}
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}