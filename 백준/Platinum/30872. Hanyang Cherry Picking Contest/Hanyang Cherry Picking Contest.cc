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
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<int> sz(n + 1);
	function<int(int, int)> dfs = [&](int u, int p) {
		sz[u] = 1;
		for (auto& v : adj[u]) {
			if (v == p) continue;
			sz[u] += dfs(v, u);
		}
		return sz[u];
	};
	dfs(1, -1);
	function<int(int, int)> dfs2 = [&](int u, int p) {
		int res = a[u];
		vector<int> hol;
		int jjam = 0;
		for (auto& v : adj[u]) {
			if (v == p) continue;
			if (sz[v] % 2) hol.push_back(dfs2(v, u)); // u를 뽑고 나서, 너가 연속해서 뽑는 것들
			else {
				int sex = dfs2(v, u);
				if (sex > 0) res -= sex;
				else jjam += sex;
			}
		}
		if (hol.size() % 2 == 1) res += jjam;
		else res -= jjam;
		sort(all(hol), greater<int>());
		for (int i = 0; i < hol.size(); i++) {
			if (i % 2 == 0) res -= hol[i];
			else res += hol[i];
		}
		return res;
	};
	int sex = dfs2(1, -1);
	if (sex == 0) cout << "Draw";
	else if (sex > 0) cout << "Sehun";
	else cout << "Cheolmin";
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}