#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

double dp[5005][10005]; // i번째까지 봤을 때 점수 j

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<double> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(all1(a), greater<>());
	dp[0][5000] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = -n; j <= n; j++) {
			if (j) dp[i][j + 5000] += dp[i - 1][j - 1 + 5000] * a[i];
			dp[i][j + 5000] = dp[i - 1][j - 1 + 5000] * a[i] + dp[i - 1][j + 1 + 5000] * (1 - a[i]);
		}
	}
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		double cur = 0;
		for (int j = k; j <= n; j++) {
			cur += dp[i][j + 5000];
		}
		ans = max(ans, cur);
	}
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}