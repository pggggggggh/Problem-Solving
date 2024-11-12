#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<int> dp(n + 1, 1e18), idxs(n + 1, -1);
	vector<int> from(n + 1);
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int idx = lower_bound(dp.begin() + 1, dp.end(), a[i]) - dp.begin();
		dp[idx] = a[i];
		idxs[idx] = i;
		from[i] = idxs[idx - 1];
		res = max(res, idx);
	}
	vector<int> path;
	int cur = idxs[res];
	while (1) {
		path.push_back(cur);
		cur = from[cur];
		if (cur == -1) break;
	}
	reverse(all(path));
	cout << path.size() << '\n';
	for (auto& x : path) cout << x << ' ';
	cout << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}