#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
#define MOD 1000000007
using namespace std;
using pi = pair<int, int>;

struct segtree {
	int sz;
	vector<int> seg;

	segtree(int n)
	{
		sz = 1;
		while (sz < n) sz *= 2;
		seg.resize(2 * sz);
	}

	void update(int x, int val)
	{
		x += sz;
		seg[x] = val;
		while (1) {
			x /= 2;
			if (!x) return;
			seg[x] = (seg[x * 2] + seg[x * 2 + 1]) % MOD;
		}
	}

	int query(int x, int y)
	{
		x += sz, y += sz;
		int res = 0;
		while (x <= y) {
			if (x & 1) res = (res + seg[x++]) % MOD;
			if (~y & 1) res = (res + seg[y--]) % MOD;
			x >>= 1, y >>= 1;
		}
		return res;
	}
};

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<pi> p;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p.emplace_back(a[i], i);
	}
	sort(all(p), [&](pi& a, pi& b) {
		if (a.first == b.first) return a.second < b.second;
		return a.first > b.first;
	});
	vector<segtree> segs(12, segtree(n + 1));
	for (auto& [_, idx] : p) {
		segs[1].update(idx, 1);
		for (int i = 2; i <= 11; i++) {
			segs[i].update(idx, segs[i - 1].query(idx + 1, n));
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) res = (res + segs[11].query(i, i)) % MOD;
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}