#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<pi> a;
	for (int i = 0; i < n; i++) {
		int v, c, k;
		cin >> v >> c >> k;
		for (int j = k; j > 0; j >>= 1) {
			int num = j - (j >> 1);
			a.emplace_back(v * num, c * num);
		}
	}
	n = a.size();
	vector dp(n + 1, vector<int>(m + 1, -1e18));
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if (j + a[i].first <= m) dp[i + 1][j + a[i].first] = max(dp[i + 1][j + a[i].first], dp[i][j] + a[i].second);
		}
	}
	int res = 0;
	for (int i = 0; i <= m; i++) res = max(res, dp[n][i]);
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}