#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

struct segtree {
	vector<int> seg;
	int sz;

	segtree(int n)
	{
		sz = 1;
		while (sz < n) sz *= 2;
		seg.resize(2 * sz);
	}

	void update(int x, int y)
	{
		x += sz;
		seg[x] = y;
		x /= 2;
		while (x) {
			seg[x] = max(seg[x * 2], seg[x * 2 + 1]);
			x /= 2;
		}
	}

	int query(int x, int y)
	{
		int res = 0;
		x += sz, y += sz;
		while (x <= y) {
			if (x & 1) res = max(res, seg[x++]);
			if (~y & 1) res = max(res, seg[y--]);
			x >>= 1, y >>= 1;
		}
		return res;
	}

	int leftmost(int x)
	{
		int cur = 1;
		if (seg[1] < x) return -1;
		while (cur < sz) {
			if (seg[cur * 2] >= x) cur *= 2;
			else cur = cur * 2 + 1;
		}
		return cur - sz;
	}
};

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	segtree seg(n);
	for (int i = 0; i < n; i++) seg.update(i, a[i]);
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int idx = seg.leftmost(b[i]);
		if (idx == -1) continue;
		ans += (i + 1) * (idx + 1);
		seg.update(idx, 0);
	}
	cout << ans << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) solve();
}