#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n + 1), psum(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0) psum[i] = psum[i - 1] + 1;
	}
	deque<pi> q;
	vector<int> dp(n + 1, 1e18);
	dp[0] = 0;
	q.push_back({ 0, 0 });
	for (int i = 1; i < n; i++) {
		if (i > k && dp[i - k] != 1e18)
			q.push_back({ dp[i - k], i - k });
		if (i < n && psum[i] < k) continue;
		while (!q.empty() && q.front().second < i - m) q.pop_front();
		if (q.empty()) continue;
		if (q.front().second >= i - k + 1) continue;
		dp[i] = q.front().first + 1;
		while (!q.empty() && q.front().first >= dp[i]) q.pop_back();

		// cout << i << '\n';
		// for (auto& [x, y] : q) cout << x << ' ' << y << '\n';
		// cout << '\n';
	}
	for (int i = n - m; i <= n - 1; i++) dp[n] = min(dp[i] + 1, dp[n]);
	cout << (dp[n] == 1e18 ? -1 : dp[n]);
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}