#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
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
	int res = 0;
	for (int i = 1; i <= n; i++) res += i / 2 * (i - i / 2);
	vector<array<int, 3>> edges(m); // {x,s,e}
	for (int i = 0; i < m; i++) {
		cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
	}
	sort(all(edges), greater<array<int, 3>>());
	union_find uf(n + 1);
	for (auto& [x, s, e] : edges) {
		if (uf.find(s) != uf.find(e)) {
			uf.uni(s, e);
			res -= x;
		}
	}
	if (res == 0) cout << "tie";
	else if (res > 0) cout << "win";
	else cout << "lose";
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}