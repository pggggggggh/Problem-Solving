#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

const int MOD = 1e9 + 7;

struct union_find {
	int n;
	vector<int> par;

	union_find(int n)
	    : n(n)
	{
		par.resize(n);
		for (int i = 0; i < n; i++) par[i] = i;
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
	}
};

void solve()
{
	vector<int> modpow = { 1 };
	for (int i = 1; i <= 3005; i++) modpow.push_back((modpow.back() * 3) % MOD);

	int n, m;
	cin >> n >> m;
	vector<pi> edges;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		edges.emplace_back(x, y);
	}
	union_find uf(n);
	int res = 0;
	for (int i = m - 1; i >= 0; i--) {
		auto& [u, v] = edges[i];
		if ((uf.find(u) == uf.find(0) && uf.find(v) == uf.find(n - 1))
		    || (uf.find(v) == uf.find(0) && uf.find(u) == uf.find(n - 1))) {
			res = (res + modpow[i]) % MOD;
		} else {
			uf.uni(u, v);
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