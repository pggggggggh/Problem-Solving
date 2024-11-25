#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

struct segtree {
	int sz;
	vector<pi> seg;

	segtree(int n)
	{
		sz = 1;
		while (sz < n) sz *= 2;
		seg.resize(2 * sz);
		for (int i = 0; i < sz; i++) seg[i] = { 1e18, -1 };
		for (int i = sz; i < 2 * sz; i++) seg[i] = { 1e18, i - sz };
	}

	void update(int x, pi val)
	{
		x += sz;
		seg[x] = val;
		while (x /= 2) seg[x] = min(seg[x * 2], seg[x * 2 + 1]);
	}

	pi query(int x, int y)
	{
		pi res = { 1e18, -1 };
		x += sz, y += sz;
		while (x <= y) {
			if (x & 1) res = min(res, seg[x++]);
			if (~y & 1) res = min(res, seg[y--]);
			x >>= 1, y >>= 1;
		}
		return res;
	}
};

static vector<int> z_func(const string& s)
{
	vector<int> z(s.size());
	z[0] = s.size();
	int l = 0, r = 0; // [l,r)
	for (int i = 1; i < s.size(); i++) {
		if (i < r) z[i] = min(r - i, z[i - l]);
		while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}
		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}
	return z;
}

void solve()
{
	int m, n;
	string b, a;
	cin >> m >> n >> b >> a;
	string c = b + "$" + a;
	vector<int> tmp = z_func(c);
	vector<int> z(n);
	a = ' ' + a;
	segtree seg(n + 2);
	for (int i = 1; i <= n; i++) z[i] = tmp[i + m];
	vector<vector<int>> dp(n + 2, vector<int>(2, 1e18)); // 0이면 시작전, 1이면 진행중 (-1 못함)
	dp[n + 1][0] = 0;
	for (int i = n; i >= 1; i--) {
		if (z[i] == m) dp[i][1] = min(dp[i][1], dp[i + m][0]);
		pi p = seg.query(i + 1, i + z[i]);
		if (p.second != -1) {
			int idx = p.second;
			dp[i][1] = min(dp[i][1], p.first - (n + 1 - p.second) + m - (idx - i));
		}
		if (dp[i][1] != 1e18) {
			seg.update(i, { dp[i][1] + n + 1 - i, i });
		}
		dp[i][0] = min(dp[i + 1][0] + 1, dp[i + 1][1] + 1);
	}
	cout << min(dp[1][0], dp[1][1]);
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}