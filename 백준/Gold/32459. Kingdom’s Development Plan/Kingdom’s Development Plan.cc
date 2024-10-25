#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<int> indegree(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		indegree[y]++;
	}
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) q.push(i);
	}
	vector<int> res;
	while (!q.empty()) {
		int v = q.top();
		q.pop();
		res.push_back(v);
		for (auto& u : adj[v]) {
			indegree[u]--;
			if (!indegree[u]) q.push(u);
		}
	}
	if (res.size() != n) {
		cout << "IMPOSSIBLE";
		return;
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}