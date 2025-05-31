#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

struct segtree {
	int sz;
	vector<int> seg;

	segtree(int n)
	{
		sz = 1;
		while (sz < n) sz *= 2;
		seg.resize(2 * n, 1e18);
	}

	void update(int x, int val)
	{
		x += sz;
		seg[x] = min(seg[x], val);
		while (1) {
			x /= 2;
			if (x == 0) return;
			seg[x] = min(seg[x * 2], seg[x * 2 + 1]);
		}
	}

	int query(int x, int y)
	{
		int ret = 1e18;
		x += sz, y += sz;
		while (x <= y) {
			if (x & 1) ret = min(ret, seg[x++]);
			if (~(y & 1)) ret = min(ret, seg[y--]);
			x >>= 1, y >>= 1;
		}
		return ret;
	}
};

void solve()
{
	int n, m;
	cin >> n;
	map<int, set<pi>> mp;
	vector<pi> a(n);
	segtree seg(500005);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	for (int i = 1; i < n; i += 2) {
		mp[a[i].second].insert({ a[i].first, a[i + 1].first });
		seg.update(a[i].first, a[i].second);
	}
	cin >> m;
	set<array<int, 3>> holes;
	for (int i = 0; i < m; i++) {
		int x, y, z, w;
		cin >> x >> y >> z >> w;
		holes.insert({ y, x, z });
	}

	double ans = 0;
	int left = 0;
	function<int(int, int, int)> dfs = [&](int s, int e, int dep) {
		int mn = seg.query(s, e - 1);
		int water = (e - s) * (mn - dep);
		vector<pi> div;
		auto it = mp[mn].lower_bound({ s, -1e18 });
		int hole = 0;
		while (it != mp[mn].end() && it->first < e) {
			div.push_back(*it);
			hole += holes.count({ mn, it->first, it->second });
			it++;
		}
		if (div.empty()) {
			left += water;
			return hole;
		}
		hole += dfs(s, div[0].first, mn);
		for (int i = 1; i < div.size(); i++) {
			hole += dfs(div[i - 1].second, div[i].first, mn);
		}
		hole += dfs(div.back().second, e, mn);
		// cout << s << ' ' << e << ' ' << dep << ' ' << hole << ' ' << water << '\n';
		if (hole == 0) left += water;
		else ans += (double)water / hole;
		return hole;
	};
	dfs(0, a.back().first, 0);
	cout << setprecision(2) << fixed << ans << '\n'
	     << left;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}