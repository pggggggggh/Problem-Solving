#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

const int MOD = 998244353;

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
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return;
	}
	if (n < 14) {
		cout << -1;
		return;
	}
	vector<int> jegops;
	for (int i = 1; i * i <= 2 * n - 1; i++) jegops.push_back(i * i);
	int ans = 29030400;
	for (int i = 15; i <= n; i++) {
		int jegop = *prev(lower_bound(all(jegops), 2 * i));
		int x = i, y = jegop - x;
		ans = ans * (x - y) % MOD;
	}
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}