#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

struct min_seg {
	int sz;
	vector<int> seg;
	min_seg(vector<int>& v)
	{
		sz = 1;
		while (sz < v.size()) sz *= 2;
		seg.resize(2 * sz, 1e18);
		for (int i = 0; i < v.size(); i++) seg[i + sz] = v[i];
		for (int i = sz - 1; i >= 1; i--) seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
	}
	int query(int x, int y)
	{
		int res = 1e18;
		x += sz, y += sz;
		while (x <= y) {
			if (x & 1) res = min(res, seg[x++]);
			if (~y & 1) res = min(res, seg[y--]);
			x >>= 1, y >>= 1;
		}
		return res;
	}
};

struct max_seg {
	int sz;
	vector<int> seg;
	max_seg(vector<int>& v)
	{
		sz = 1;
		while (sz < v.size()) sz *= 2;
		seg.resize(2 * sz, -1e18);
		for (int i = 0; i < v.size(); i++) seg[i + sz] = v[i];
		for (int i = sz - 1; i >= 1; i--) seg[i] = max(seg[i * 2], seg[i * 2 + 1]);
	}
	int query(int x, int y)
	{
		int res = -1e18;
		x += sz, y += sz;
		while (x <= y) {
			if (x & 1) res = max(res, seg[x++]);
			if (~y & 1) res = max(res, seg[y--]);
			x >>= 1, y >>= 1;
		}
		return res;
	}
};

void solve()
{
	int n, cap;
	cin >> cap >> n;
	vector<int> a(n + 1), psum(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
	}
	min_seg minseg(psum);
	max_seg maxseg(psum);
	vector<int> zerostart(n + 2), infstart(n + 2);
	zerostart[n + 1] = 0;
	infstart[n + 1] = cap;
	for (int i = n; i >= 1; i--) {
		int lo = i - 1, hi = n + 1;
		while (lo + 1 < hi) {
			int mid = lo + hi >> 1;
			if (minseg.query(i, mid) <= psum[i - 1]) hi = mid;
			else lo = mid;
		}
		int firstzero = hi;
		lo = i - 1, hi = n + 1;
		while (lo + 1 < hi) {
			int mid = lo + hi >> 1;
			if (maxseg.query(i, mid) >= cap + psum[i - 1]) hi = mid;
			else lo = mid;
		}
		int firstinf = hi;
		lo = i - 1, hi = n + 1;
		while (lo + 1 < hi) {
			int mid = lo + hi >> 1;
			if (minseg.query(i, mid) + cap <= psum[i - 1]) hi = mid;
			else lo = mid;
		}
		int infstartfirstzero = hi;
		lo = i - 1, hi = n + 1;
		while (lo + 1 < hi) {
			int mid = lo + hi >> 1;
			if (maxseg.query(i, mid) + cap >= cap + psum[i - 1]) hi = mid;
			else lo = mid;
		}
		int infstartfirstinf = hi;

		if (firstzero > n && firstinf > n) {
			zerostart[i] = psum[n] - psum[i - 1];
		} else if (firstzero < firstinf) {
			zerostart[i] = zerostart[firstzero + 1];
		} else {
			zerostart[i] = infstart[firstinf + 1];
		}
		if (infstartfirstzero > n && infstartfirstinf > n) {
			infstart[i] = min(cap + psum[n] - psum[i - 1], cap);
		} else if (infstartfirstzero < infstartfirstinf) {
			infstart[i] = zerostart[infstartfirstzero + 1];
		} else {
			infstart[i] = infstart[infstartfirstinf + 1];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		int lo = 0, hi = n + 1;
		while (lo + 1 < hi) {
			int mid = lo + hi >> 1;
			if (minseg.query(1, mid) + x <= 0) hi = mid;
			else lo = mid;
		}
		int firstzero = hi;
		lo = 0, hi = n + 1;
		while (lo + 1 < hi) {
			int mid = lo + hi >> 1;
			if (x + maxseg.query(1, mid) >= cap) hi = mid;
			else lo = mid;
		}
		int firstinf = hi;

		if (firstzero > n && firstinf > n) {
			cout << psum[n] + x << '\n';
		} else if (firstzero < firstinf) {
			cout << zerostart[firstzero + 1] << '\n';
		} else {
			cout << infstart[firstinf + 1] << '\n';
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}