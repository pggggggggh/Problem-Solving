#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
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
			if (~(y & 1)) res = min(res, seg[y--]);
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

void solve()
{
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	minseg psum(n + 2); // 1 based
	vector<set<int>> psumpos(2 * n + 1);
	int cur = 0;
	psum.update(0, 0);
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') cur++;
		else cur--;
		psum.update(i + 1, cur);
		psumpos[cur + n].insert(i);
	}
	psum.update(n + 1, -1e18);

	string a = s + '$' + t;
	int l = n + m + 1;
	vector<int> pos(l), sa(l);
	vector<int> lcps(l);
	for (int i = 0; i < l; i++) {
		sa[i] = i;
		pos[i] = a[i];
	}
	int d = 1;
	auto cmp = [&](int i, int j) {
		if (pos[i] != pos[j]) return pos[i] < pos[j];
		i += d, j += d;
		if (i >= l || j >= l) return i > j;
		return pos[i] < pos[j];
	};
	while (1) {
		sort(all(sa), cmp);
		vector<int> tmp(l);
		for (int i = 1; i < l; i++) tmp[i] = tmp[i - 1] + cmp(sa[i - 1], sa[i]);
		for (int i = 0; i < l; i++) pos[sa[i]] = tmp[i];
		if (tmp[l - 1] == l - 1) break;
		d *= 2;
	}
	int ans = 0;
	int k = 0;
	for (int i = 0; i < l - 1; i++, k = max(k - 1, 0LL)) {
		if (pos[i] == l - 1) continue;
		int x = i, y = sa[pos[i] + 1];
		if (x == n || y == n) continue;
		while (a[x + k] == a[y + k]) k++;
		if (x > y) swap(x, y);
		if (k == 0) continue;
		if (a[x] == ')') continue;
		if ((x < n) ^ (y < n)) {
			// for (int j = x; j < l; j++) cout << a[j];
			// cout << ' ';
			// for (int j = y; j < l; j++) cout << a[j];
			// cout << ':' << k << '\n';
			int lo = x, hi = n;
			int lb = psum.query(x, x); // x-1+1
			while (lo + 1 < hi) {
				int mid = lo + hi >> 1;
				if (psum.query(x + 1, mid + 1) >= lb) lo = mid;
				else hi = mid;
			}
			int ub = min(x + k - 1, lo);
			auto it = psumpos[lb + n].upper_bound(ub);
			if (it != psumpos[lb + n].begin()) {
				ans = max(ans, (*prev(it)) - x + 1);
				// cout << x << ' ' << (*(prev(it))) << '\n';
			}
		}
	}
	cout << ans << '\n';
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