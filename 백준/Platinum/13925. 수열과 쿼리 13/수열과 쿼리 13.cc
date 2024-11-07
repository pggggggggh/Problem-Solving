#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

const int MOD = 1e9 + 7;

struct lazyprop {
	struct node {
		int a, b;
		node operator+(const node& x)
		{
			return { (a * x.a) % MOD, (b * x.a + x.b) % MOD };
		}
		node operator+=(const node& x)
		{
			*this = *this + x;
			return *this;
		}
	};

	int sz;
	vector<int> seg;
	vector<node> lazy;

	lazyprop(vector<int>& a)
	{
		int n = a.size();
		sz = 1;
		while (sz < n) sz *= 2;
		seg.resize(2 * sz);
		lazy.resize(2 * sz, { 1, 0 });
		for (int i = 0; i < n; i++) seg[i + sz] = a[i];
		for (int i = sz - 1; i >= 1; i--) seg[i] = (seg[i * 2] + seg[i * 2 + 1]) % MOD;
	}

	void propa(int node, int l, int r)
	{
		seg[node] = (seg[node] * lazy[node].a % MOD + lazy[node].b * (r - l + 1) % MOD) % MOD;
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = { 1, 0 };
	}

	void add_range(int x, int y, node val, int node, int l, int r)
	{
		propa(node, l, r);
		if (r < x || y < l) return;
		if (x <= l && r <= y) {
			lazy[node] += val;
			propa(node, l, r);
			return;
		}
		int mid = l + r >> 1;
		add_range(x, y, val, node * 2, l, mid);
		add_range(x, y, val, node * 2 + 1, mid + 1, r);
		seg[node] = (seg[node * 2] + seg[node * 2 + 1]) % MOD;
	}

	int query(int x, int y, int node, int l, int r)
	{
		propa(node, l, r);
		if (r < x || y < l) return 0;
		if (x <= l && r <= y) return seg[node];
		int mid = l + r >> 1;
		return (query(x, y, node * 2, l, mid) + query(x, y, node * 2 + 1, mid + 1, r)) % MOD;
	}
};

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	lazyprop seg(a);
	int q;
	cin >> q;
	while (q--) {
		int w, x, y, z;
		cin >> w >> x >> y;
		if (w != 4) cin >> z;
		if (w == 1) seg.add_range(x, y, { 1, z }, 1, 0, seg.sz - 1);
		else if (w == 2) seg.add_range(x, y, { z, 0 }, 1, 0, seg.sz - 1);
		else if (w == 3) seg.add_range(x, y, { 0, z }, 1, 0, seg.sz - 1);
		else cout << seg.query(x, y, 1, 0, seg.sz - 1) << '\n';
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}