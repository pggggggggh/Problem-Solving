#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define ll long long
using namespace std;
using pi = pair<int, int>;

struct segtree {
	int sz;
	vector<int> seg;

	segtree(int n)
	{
		sz = 1;
		while (sz < n) sz *= 2;
		seg.resize(2 * sz, 1e9);
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
		int ret = 1e9;
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
	segtree seg(5000005);
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

	ll left = 0;
	map<pi, double> timedp;
	function<int(int, int, int)> dfs = [&](int s, int e, int dep) {
		if (s == e) return 0;
		double& time = timedp[{ s, e }];

		int mn = seg.query(s, e - 1);
		ll water = (ll)(e - s) * (mn - dep);
		vector<pi> div;
		auto it = mp[mn].lower_bound({ s, -1e18 });
		int hole = 0;
		while (it != mp[mn].end() && it->first < e) {
			div.push_back(*it);
			hole += holes.count({ mn, it->first, it->second });
			it++;
		}
		if (div.empty()) {
			left += (ll)water;
			return hole;
		}
		hole += dfs(s, div[0].first, mn);

		if (timedp.find({ s, div[0].first }) != timedp.end())
			time = max(time, timedp[{ s, div[0].first }]);
		for (int i = 1; i < div.size(); i++) {
			hole += dfs(div[i - 1].second, div[i].first, mn);
			if (timedp.find({ div[i - 1].second, div[i].first }) != timedp.end())
				time = max(time, timedp[{ div[i - 1].second, div[i].first }]);
		}
		hole += dfs(div.back().second, e, mn);
		if (timedp.find({ div.back().second, e }) != timedp.end())
			time = max(time, timedp[{ div.back().second, e }]);

		if (hole == 0) left += water;
		else time += (double)water / hole;

		return hole;
	};
	dfs(0, a.back().first, 0);
	cout << setprecision(2) << fixed << timedp[{ 0, a.back().first }] << '\n'
	     << left;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}