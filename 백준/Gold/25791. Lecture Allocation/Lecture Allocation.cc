#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

int dp[5005][5005];

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>> a(k + 1, vector<int>(4));
	for (int i = 1; i <= k; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}
	for (int i = 1; i <= n; i++) dp[0][i] = 1e18;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) dp[i][j] = dp[i - 1][j];
		for (int j = 1; j <= 3; j++) {
			for (int k = 0; k <= n; k++) {
				if (k - j < 0) continue;
				dp[i][k] = min(dp[i - 1][k - j] + a[i][j], dp[i][k]);
			}
		}
	}

	int res = 1e18;
	for (int i = 1; i <= k; i++) res = min(res, dp[i][n]);
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}