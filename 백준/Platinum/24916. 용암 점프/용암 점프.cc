#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 2);
	a[0] = 1e18;
	a[n + 1] = -1e18;
	vector<pi> b;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i > 1) b.push_back({ a[i] - a[i - 1], i });
	}
	if (n == 1) {
		cout << "YES\n";
		return;
	}
	map<array<int, 4>, int> dp;
	function<int(int, int, int, int)> go = [&](int s, int e, int se, int lastcha) {
		if (dp.find({ s, e, se, lastcha }) != dp.end()) {
			return dp[{ s, e, se, lastcha }];
		}
		int& ret = dp[{ s, e, se, lastcha }];
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
	sort(all(b));
	set<int> candi;
	for (int i = 1; i <= n; i++) candi.insert(i);
	for (int i = 0; i < min((int)b.size(), 500LL); i++) {
		int idx = b[i].second;
		candi.insert(idx);
		if (idx < n) candi.insert(idx + 1);
		candi.insert(idx - 1);
	}
	for (auto& i : candi) {
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