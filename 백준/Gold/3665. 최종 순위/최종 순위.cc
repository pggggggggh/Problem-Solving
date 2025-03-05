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
	vector<int> a(n + 1);
	vector<set<int>> adj(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			adj[a[i]].insert(a[j]);
		}
	}
	int m;
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		if (adj[x].count(y)) {
			adj[x].erase(y);
			adj[y].insert(x);
		} else {
			adj[y].erase(x);
			adj[x].insert(y);
		}
	}
	queue<int> q;
	vector<int> ind(n + 1);
	for (int i = 1; i <= n; i++) {
		for (auto& x : adj[i]) ind[x]++;
	}
	for (int i = 1; i <= n; i++)
		if (ind[i] == 0) q.push(i);

	vector<int> p;
	while (!q.empty()) {
		auto u = q.front();
		p.push_back(u);
		q.pop();

		for (auto& v : adj[u]) {
			ind[v]--;
			if (ind[v] == 0) q.push(v);
		}
	}
	if (p.size() != n) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	for (auto& x : p) cout << x << ' ';
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