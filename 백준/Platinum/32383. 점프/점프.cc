#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

struct segtree {
	int sz;
	vector<pi> seg;

	segtree(int n)
	{
		sz = 1;
		while (sz < n) sz *= 2;
		seg.resize(2 * sz);
	}

	void update(int x, int _val)
	{
		pi val = { _val, x };
		x += sz;
		while (1) {
			seg[x] = max(seg[x], val);
			if (x == 1) break;
			x /= 2;
		}
	}

	pi query(int x, int y)
	{
		pi res = { 0, 0 };
		x += sz, y += sz;
		while (x <= y) {
			if (x % 2) res = max(seg[x++], res);
			if (!(y % 2)) res = max(seg[y--], res);
			x >>= 1, y >>= 1;
		}
		return res;
	}
};

const int MOD = 1e9 + 7;

int n;
int a[500005];
vector<pi> g[500005];
int sz[500005];
segtree seg(500005);
int parcost[500005];

int recur(int s, int e)
{
	int x = seg.query(s, e).second;
	if (s <= x - 1) {
		int y = recur(s, x - 1);
		g[x].push_back({ y, (a[x] - a[y]) * (a[x] - a[y]) % MOD });
	}
	if (x + 1 <= e) {
		int y = recur(x + 1, e);
		g[x].push_back({ y, (a[x] - a[y]) * (a[x] - a[y]) % MOD });
	}
	return x;
}

void treedp(int u)
{
	sz[u] = 1;
	for (auto& [v, foo] : g[u]) {
		treedp(v);
		sz[u] += sz[v];
		parcost[v] = foo;
	}
}

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		seg.update(i, a[i]);
	}
	int root = recur(1, n);
	treedp(root);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + (parcost[i] * sz[i] % MOD * (n - sz[i]) % MOD)) % MOD;
	}
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}