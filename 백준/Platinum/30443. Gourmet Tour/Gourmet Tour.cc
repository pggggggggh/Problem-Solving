#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	vector<int> degree(n + 1);
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		degree[x]++;
		degree[y]++;
	}
	auto bfs = [&](vector<int>& dist, int s) {
		queue<pi> q;
		vector<int> vis(n + 1);
		q.push({ 0, s });
		while (!q.empty()) {
			auto [d, u] = q.front();
			dist[u] = d;
			q.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			for (auto& v : adj[u]) {
				if (vis[v]) continue;
				q.push({ d + 1, v });
			}
		}
	};
	vector<int> dist1(n + 1), dist2(n + 1);
	bfs(dist1, 1);
	int v1 = max_element(all(dist1)) - dist1.begin();
	bfs(dist2, v1);
	int v2 = max_element(all(dist2)) - dist2.begin();
	int cur = v1;
	int bf = 0; // 0이면 back
	vector<int> vis(n + 1);
	deque<int> dq;
	while (1) {
		vis[cur] = 1;
		if (bf) dq.push_front(cur);
		else dq.push_back(cur);
		bf = 1 - bf;
		for (auto& v : adj[cur]) {
			if (vis[v]) continue;
			if (v != v2 && degree[v] == 1) {
				if (bf) dq.push_front(v);
				else dq.push_back(v);
			}
		}

		if (cur == v2) break;

		for (auto& v : adj[cur]) {
			if (vis[v]) continue;
			if (v == v2 || degree[v] > 1) {
				cur = v;
				break;
			}
		}
	}
	vector<int> ans(n + 1);
	for (int i = 0; i < dq.size(); i++) ans[dq[i]] = i + 1;
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}