#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

const int MOD = 1e9 + 7;

struct segtree {
	const pi E = { -1e18, 0 };

	pi op(pi x, pi y)
	{
		if (x.first > y.first) return x;
		if (x.first < y.first) return y;
		return { x.first, (x.second + y.second) % MOD };
	}

	int sz;
	vector<pi> seg;

	segtree(int n)
	{
		sz = 1;
		while (sz < n) sz *= 2;
		seg.resize(2 * sz, E);
	}

	void put(int x, pi y)
	{
		x += sz;
		seg[x] = y;
		while (1) {
			x /= 2;
			if (x == 0) return;
			seg[x] = op(seg[x * 2], seg[x * 2 + 1]);
		}
	}

	pi query(int s, int e)
	{
		pi res = E;
		s += sz, e += sz;
		while (s <= e) {
			if (s & 1) res = op(res, seg[s++]);
			if (!(e & 1)) res = op(res, seg[e--]);
			s >>= 1, e >>= 1;
		}
		return res;
	}
};

map<int, vector<int>> idxs;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		idxs[a[i]].push_back(i);
	}
	segtree seg(n + 1);
	seg.put(0, { 0, 1 });
	int ansl = 0;
	for (auto& [foo, st] : idxs) {
		vector<pair<int, pi>> batch;
		for (auto& i : st) {
			pi x = seg.query(0, i - 1);
			batch.push_back({ i, { x.first + 1, x.second } });
			ansl = max(ansl, x.first + 1);
		}
		for (auto& [x, y] : batch) seg.put(x, y);
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		auto& x = seg.seg[i + seg.sz];
		if (x.first == ansl) ans = (ans + x.second) % MOD;
	}
	cout << ansl << ' ' << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}