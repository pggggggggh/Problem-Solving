#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

struct lazyprop {
	int sz;
	vector<int> seg, lazy;

	lazyprop(int n)
	{
		sz = 1;
		while (sz < n) sz *= 2;
		seg.resize(2 * sz);
		lazy.resize(2 * sz);
	}

	void propa(int node, int l, int r)
	{
		if (lazy[node] == 0) return;
		seg[node] += lazy[node] * (r - l + 1);
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	void update(int x, int val, int node = 1, int l = 0, int r = -1)
	{
		if (r == -1) r = sz - 1;
		propa(node, l, r);
		if (l == r) {
			seg[node] = val;
			return;
		}
		int mid = l + r >> 1;
		if (x <= mid) update(x, val, node * 2, l, mid);
		else update(x, val, node * 2 + 1, mid + 1, r);
		seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}

	void range_update(int x, int y, int val, int node = 1, int l = 0, int r = -1)
	{
		if (r == -1) r = sz - 1;
		propa(node, l, r);
		if (y < l || r < x) return;
		if (x <= l && r <= y) {
			lazy[node] += val;
			propa(node, l, r);
			return;
		}
		int mid = l + r >> 1;
		range_update(x, y, val, node * 2, l, mid);
		range_update(x, y, val, node * 2 + 1, mid + 1, r);
		seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}

	int query(int x, int y, int node = 1, int l = 0, int r = -1)
	{
		if (r == -1) r = sz - 1;
		propa(node, l, r);
		if (y < l || r < x) return 0;
		if (x <= l && r <= y) return seg[node];
		int mid = l + r >> 1;
		return query(x, y, node * 2, l, mid) + query(x, y, node * 2 + 1, mid + 1, r);
	}
};

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	int q = m + k;
	lazyprop seg(n + 1);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		seg.update(i, x);
	}
	while (q--) {
		int x, y, z, w;
		cin >> x >> y >> z;
		if (y > z) swap(y, z);
		if (x == 1) {
			cin >> w;
			seg.range_update(y, z, w);
		} else cout << seg.query(y, z) << '\n';
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}