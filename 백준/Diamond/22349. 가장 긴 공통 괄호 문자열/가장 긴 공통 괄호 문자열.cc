#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
#define int128 __int128_t
using namespace std;
using pi = pair<int, int>;

struct minseg {
	int sz;
	vector<int> seg;

	minseg(int n)
	{
		sz = 1;
		while (sz < n) sz *= 2;
		seg.resize(2 * sz, 1e18);
	}

	int query(int x, int y)
	{
		int res = 1e18;
		x += sz, y += sz;
		while (x <= y) {
			if (x & 1) res = min(res, seg[x++]);
			if (!(y & 1)) res = min(res, seg[y--]);
			x >>= 1, y >>= 1;
		}
		return res;
	}

	void update(int x, int val)
	{
		x += sz;
		seg[x] = val;
		x /= 2;
		while (x) {
			seg[x] = min(seg[x * 2], seg[x * 2 + 1]);
			x /= 2;
		}
	}
};

const int sz = 10;
const vector<int> MOD = {
	100000000003LL,
	100000000019LL,
	100000000057LL,
	100000000063LL,
	100000000069LL,
	100000000099LL,
	100000000103LL,
	100000000129LL,
	100000000163LL,
	100000000169LL,
	100000000193LL,
	100000000223LL,
	100000000237LL,
	100000000253LL,
	100000000267LL,
	100000000279LL,
	100000000319LL,
	100000000323LL,
	100000000379LL,
	100000000399LL,
	100000000403LL,
	100000000429LL,
	100000000471LL,
	100000000503LL,
	100000000517LL,
	100000000529LL,
	100000000553LL,
	100000000577LL,
	100000000583LL,
	100000000607LL,
};

int modexp(int128 x, int128 y, int128 m)
{
	int128 res = 1;
	while (y) {
		if (y % 2) res = res * x % m;
		x = x * x % m;
		y >>= 1;
	}
	return res;
}

void solve()
{
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	s = '$' + s, t = '$' + t;
	minseg psum(n + 1), psumb(m + 1);
	int cur = 0;
	psum.update(0, 0);
	for (int i = 1; i <= n; i++) {
		if (s[i] == '(') cur++;
		else cur--;
		psum.update(i, cur);
	}
	cur = 0;
	psumb.update(0, 0);
	for (int i = 1; i <= m; i++) {
		if (t[i] == '(') cur++;
		else cur--;
		psumb.update(i, cur);
	}
	int lo = 0, hi = min(n, m) / 2 + 1;
	while (lo + 1 < hi) {
		int mid = lo + hi >> 1;
		int len = mid * 2;
		array<int, sz> cur = { 0, 0, 0, 0 };
		vector<array<int, sz>> ar;
		for (int i = 1; i <= len; i++) {
			if (s[i] == '(') {
				for (int k = 0; k < sz; k++) {
					cur[k] = (cur[k] + modexp(2, len - i, MOD[k])) % MOD[k];
				}
			}
		}
		if (psum.query(len, len) == psum.query(0, 0) && psum.query(0, len) >= psum.query(0, 0)) {
			ar.push_back(cur);
		}
		for (int i = len + 1; i <= n; i++) {
			if (s[i - len] == '(') {
				for (int k = 0; k < sz; k++) {
					cur[k] = (cur[k] - modexp(2, len - 1, MOD[k]) + MOD[k]) % MOD[k];
				}
			}
			for (int k = 0; k < sz; k++) cur[k] = cur[k] * 2 % MOD[k];
			if (s[i] == '(') {
				for (int k = 0; k < sz; k++) cur[k] = (cur[k] + 1) % MOD[k];
			}
			if (psum.query(i, i) == psum.query(i - len, i - len) && psum.query(i - len, i) >= psum.query(i - len, i - len)) {
				ar.push_back(cur);
			}
		}
		sort(all(ar));
		ar.erase(unique(all(ar)), ar.end());
		cur = { 0, 0, 0, 0 };

		for (int i = 1; i <= len; i++) {
			if (t[i] == '(') {
				for (int k = 0; k < sz; k++) {
					cur[k] = (cur[k] + modexp(2, len - i, MOD[k])) % MOD[k];
				}
			}
		}

		int good = 0;
		auto it = lower_bound(all(ar), cur);
		if (it != ar.end()) {
			if (*it == cur) {
				good = 1;
			}
		}

		for (int i = len + 1; i <= m; i++) {
			if (good) break;
			if (t[i - len] == '(') {
				for (int k = 0; k < sz; k++) {
					cur[k] = (cur[k] - modexp(2, len - 1, MOD[k]) + MOD[k]) % MOD[k];
				}
			}
			for (int k = 0; k < sz; k++) cur[k] = cur[k] * 2 % MOD[k];
			if (t[i] == '(') {
				for (int k = 0; k < sz; k++) cur[k] = (cur[k] + 1) % MOD[k];
			}
			if (psumb.query(i, i) == psumb.query(i - len, i - len) && psumb.query(i - len, i) >= psumb.query(i - len, i - len)) {
				auto it = lower_bound(all(ar), cur);
				if (it != ar.end()) {
					if (*lower_bound(all(ar), cur) == cur) {
						good = 1;
					}
				}
			}
		}
		if (good) {
			// cout << mid << "good\n";
			lo = mid;
		} else hi = mid;
	}
	cout << lo * 2 << '\n';
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