#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<int> r(n + 1), l(m + 1);
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			adj[i].push_back(x);
		}
	}
	vector<int> vis(n + 1);
	function<int(int)> go = [&](int u) {
		vis[u] = 1;
		for (auto& v : adj[u]) {
			if (l[v] == 0 || (!vis[l[v]] && go(l[v]))) {
				r[u] = v;
				l[v] = u;
				return 1;
			}
		}
		return 0;
	};
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (r[i] == 0) {
			fill(all(vis), 0);
			res += go(i);
		}
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