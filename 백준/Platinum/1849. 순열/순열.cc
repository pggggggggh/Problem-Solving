#include <bits/stdc++.h>
#define int long long
using namespace std;

struct segtree {
	int sz;
	vector<int> seg;

	segtree(int n)
	{
		sz = 1;
		while (sz < n) sz *= 2;
		seg.resize(2 * sz);
		for (int i = sz + 1; i <= sz + n; i++) seg[i] = 1;
		for (int i = sz - 1; i >= 1; i--) seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}

	void update(int x, int val)
	{
		x += sz;
		seg[x] = val;
		while (x /= 2) seg[x] = seg[2 * x] + seg[2 * x + 1];
	}

	int query(int x, int y)
	{
		int res = 0;
		x += sz, y += sz;
		while (x <= y) {
			if (x & 1) res += seg[x++];
			if (~y & 1) res += seg[y--];
			x >>= 1, y >>= 1;
		}
		return res;
	}

	int kth(int k)
	{
		int cur = 1;
		while (cur < sz) {
			if (seg[cur * 2] >= k) cur *= 2;
			else {
				k -= seg[cur * 2];
				cur = cur * 2 + 1;
			}
		}
		return cur - sz;
	}
};

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	segtree seg(n + 1);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		int idx = seg.kth(x + 1);
		a[idx] = i;
		seg.update(idx, 0);
	}
	for (int i = 1; i <= n; i++) cout << a[i] << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
}