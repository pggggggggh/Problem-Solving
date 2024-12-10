#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
// #define int long long
using namespace std;
using pi = pair<int, int>;

const int m = 1e3;

inline long long hsh(int x, int y, int z)
{
	return (x * m * m + y * m + z);
}

int a[100005];
unordered_map<long long, int> dp;

void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i <= n + 1; i++) a[i] = 0;
	a[0] = 1e9;
	a[n + 1] = -1e9;
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

	function<int(int, int, int)> go = [&](int s, int e, int sex) {
		int jyheo = hsh(s, e, sex);
		if (dp.find(jyheo) != dp.end()) {
			return dp[jyheo];
		}
		int& ret = dp[jyheo];
		if (s == 1 && e == n) return ret = 1;
		int lastcha, se;
		if (sex == 0) {
			se = 0;
			lastcha = a[s + 1] - a[s];
		} else if (sex == 1) {
			se = 1;
			lastcha = a[e] - a[s];
		} else if (sex == 2) {
			se = 1;
			lastcha = a[e] - a[e - 1];
		} else {
			se = 0;
			lastcha = a[e] - a[s];
		}
		if (s == e) {
			se = 0;
			lastcha = 0;
		}
		if (se == 0) {
			if (a[s] - a[s - 1] >= 2 * lastcha) {
				if (go(s - 1, e, 0)) return ret = 1;
			}
			if (a[e + 1] - a[s] >= 2 * lastcha) {
				if (go(s, e + 1, 1)) return ret = 1;
			}
		} else {
			if (a[e + 1] - a[e] >= 2 * lastcha) {
				if (go(s, e + 1, 2)) return ret = 1;
			}
			if (a[e] - a[s - 1] >= 2 * lastcha) {
				if (go(s - 1, e, 3)) return ret = 1;
			}
		}
		return ret = 0;
	};
	for (int i = 1; i <= n; i++) {
		dp.clear();
		if (go(i, i, 0)) cout << "YES\n";
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