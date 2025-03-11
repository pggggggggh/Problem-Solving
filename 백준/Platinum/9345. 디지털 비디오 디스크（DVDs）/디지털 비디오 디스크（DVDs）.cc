#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

struct maxseg {
	int sz;
	vector<int> seg;

	maxseg(int n)
	{
		sz = 1;
		while (sz < n) sz *= 2;
		seg.resize(2 * sz, 0);
	}

	void update(int x, int y)
	{
		x += sz;
		seg[x] = y;
		while (1) {
			x /= 2;
			if (!x) return;
			seg[x] = max(seg[x * 2], seg[x * 2 + 1]);
		}
	}

	int query(int x, int y)
	{
		x += sz, y += sz;
		int res = 0;
		while (x <= y) {
			if (x & 1) res = max(res, seg[x++]);
			if (~y & 1) res = max(res, seg[y--]);
			x >>= 1, y >>= 1;
		}
		return res;
	}
};

struct minseg {
	int sz;
	vector<int> seg;

	minseg(int n)
	{
		sz = 1;
		while (sz < n) sz *= 2;
		seg.resize(2 * sz, 1e18);
	}

	void update(int x, int y)
	{
		x += sz;
		seg[x] = y;
		while (1) {
			x /= 2;
			if (!x) return;
			seg[x] = min(seg[x * 2], seg[x * 2 + 1]);
		}
	}

	int query(int x, int y)
	{
		x += sz, y += sz;
		int res = 1e18;
		while (x <= y) {
			if (x & 1) res = min(res, seg[x++]);
			if (~y & 1) res = min(res, seg[y--]);
			x >>= 1, y >>= 1;
		}
		return res;
	}
};

void solve()
{
	int n, q;
	cin >> n >> q;
	maxseg mxseg(n);
	minseg mnseg(n);
	for (int i = 0; i < n; i++) {
		mxseg.update(i, i);
		mnseg.update(i, i);
	}
	while (q--) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 0) {
			int a = mxseg.query(y, y), b = mxseg.query(z, z);
			mxseg.update(y, b);
			mxseg.update(z, a);
			mnseg.update(y, b);
			mnseg.update(z, a);
		} else {
			cout << (mnseg.query(y, z) == y && mxseg.query(y, z) == z ? "YES" : "NO") << '\n';
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
}