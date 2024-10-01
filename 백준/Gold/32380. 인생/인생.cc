#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

struct lazyseg {
	using S = int;
	using L = int;
	const S seg_e = 0;   // identity of seg_op
	const L lazy_e = 0;  // identity of lazy_op

	S seg_op(S a, S b) {  // combine two nodes
		return a + b;
	}

	L lazy_op(L a, L b) {  // combine two lazy values
		return a + b;
	}

	void apply_lazy(S &s, L l, int len) {
		s += l * len;
	}

	int n, sz;
	vector<S> seg;
	vector<L> lazy;

	lazyseg(int n, const vector<S> &v = vector<S>()) {
		assert(n >= v.size());
		this->n = n;
		sz = 1;
		while (sz < n) sz *= 2;
		seg = vector(2 * sz, seg_e);
		lazy = vector(2 * sz, lazy_e);
		for (int i = 0; i < v.size(); i++) seg[i + sz] = v[i];
		for (int i = sz - 1; i >= 1; i--)
			seg[i] = seg_op(seg[i * 2], seg[i * 2 + 1]);
	}

	void propa(int node, int l, int r) {
		if (lazy[node] == lazy_e) return;
		apply_lazy(seg[node], lazy[node], r - l + 1);
		if (l != r) {
			lazy[node * 2] = lazy_op(lazy[node * 2], lazy[node]);
			lazy[node * 2 + 1] = lazy_op(lazy[node * 2 + 1], lazy[node]);
		}
		lazy[node] = lazy_e;
	}

	void put(int x, S val, int node, int l, int r) {
		propa(node, l, r);
		if (l == r) {
			seg[node] = val;
			return;
		}
		int mid = l + r >> 1;
		if (x <= mid)
			put(x, val, node * 2, l, mid);
		else
			put(x, val, node * 2 + 1, mid + 1, r);
		seg[node] = seg_op(seg[node * 2], seg[node * 2 + 1]);
	}

	void put(int x, S val) {
		put(x, val, 1, 0, sz - 1);
	}

	void add(int x, int y, S val, int node, int l, int r) {
		propa(node, l, r);
		if (r < x || y < l) return;
		if (x <= l && r <= y) {
			lazy[node] = lazy_op(lazy[node], val);
			propa(node, l, r);
			return;
		}
		int mid = l + r >> 1;
		add(x, y, val, node * 2, l, mid);
		add(x, y, val, node * 2 + 1, mid + 1, r);
		seg[node] = seg_op(seg[node * 2], seg[node * 2 + 1]);
	}

	void add(int x, int y, S val) {
		add(x, y, val, 1, 0, sz - 1);
	}

	S query(int x, int y, int node, int l, int r) {
		propa(node, l, r);
		if (r < x || y < l) return seg_e;
		if (x <= l && r <= y) return seg[node];
		int mid = l + r >> 1;
		return seg_op(query(x, y, node * 2, l, mid),
		              query(x, y, node * 2 + 1, mid + 1, r));
	}

	S query(int x, int y) {
		return query(x, y, 1, 0, sz - 1);
	}
};

void solve() {
	int n, u, d;
	cin >> n >> u >> d;
	vector<int> a(n + 1), b(n + 1);
	lazyseg seg(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		seg.add(i, i, min(a[i], b[i]));
		int flip = (b[i] - a[i] + (u + d - 1)) / (u + d);
		if (flip <= 0) {
			seg.add(i + 1, n, -d);
		} else {
			seg.add(i + 1, i + flip - 1, u);
			int before = a[i] + u * (flip - 1);
			int after = b[i] - d * flip;
			seg.add(i + flip, i + flip, after - before);
			seg.add(i + flip + 1, n, -d);
		}
		// for (int j = 1; j <= n; j++) {
		// 	cout << seg.query(j, j) << ' ';
		// }
		// cout << '\n';
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res += seg.query(i, i);
		cout << res << '\n';
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}