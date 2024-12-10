#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

const int m = 1e3;

inline int hsh(int x, int y, int z, int w)
{
	return x * m * m * m + y * m * m + z * m + w;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 2);
	a[0] = 1e18;
	a[n + 1] = -1e18;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << "YES\n";
		return;
	}
	if (n > 22) {
		for (int i = 1; i <= n; i++) cout << "NO\n";
		return;
	}
	unordered_map<int, int> dp;
	function<int(int, int, int, int)> go = [&](int s, int e, int se, int lastcha) {
		int jyheo = hsh(s, e, se, lastcha);
		if (dp.find(jyheo) != dp.end()) {
			return dp[jyheo];
		}
		int& ret = dp[jyheo];
		if (s == 1 && e == n) return ret = 1;
		if (se == 0) {
			if (a[s] - a[s - 1] >= 2 * lastcha) {
				if (go(s - 1, e, 0, a[s] - a[s - 1])) return ret = 1;
			}
			if (a[e + 1] - a[s] >= 2 * lastcha) {
				if (go(s, e + 1, 1, a[e + 1] - a[s])) return ret = 1;
			}
		} else {
			if (a[e + 1] - a[e] >= 2 * lastcha) {
				if (go(s, e + 1, 1, a[e + 1] - a[e])) return ret = 1;
			}
			if (a[e] - a[s - 1] >= 2 * lastcha) {
				if (go(s - 1, e, 0, a[e] - a[s - 1])) return ret = 1;
			}
		}
		return ret = 0;
	};
	for (int i = 1; i <= n; i++) {
		dp.clear();
		if (go(i, i, 0, 0)) cout << "YES\n";
		else cout << "NO\n";
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) solve();
}