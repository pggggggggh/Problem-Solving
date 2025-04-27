#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

struct union_find {
	int n;
	vector<int> par, sz;

	union_find(int n)
	    : n(n)
	{
		par.resize(n);
		sz.resize(n);
		for (int i = 0; i < n; i++) {
			par[i] = i;
			sz[i] = 1;
		}
	}

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
		par[y] = x;
		sz[x] += sz[y];
	}
};

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<pi> a(m);
	union_find uf(1000001);
	for (int i = 0; i < m; i++) {
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 0; i < m; i++) uf.uni(a[i].first, a[i].second);
	vector<int> edges(1000001);
	for (int i = 0; i < m; i++) {
		edges[uf.find(a[i].first)]++;
	}
	int ans = 0;
	for (int i = 0; i < 1000001; i++) {
		if (uf.find(i) == i) {
			ans += edges[i] - uf.sz[i] + 1;
		}
	}
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}