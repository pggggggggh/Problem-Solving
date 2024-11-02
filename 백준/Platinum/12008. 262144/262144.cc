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
	vector dp(n + 2, vector<int>(65, -1));
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i][a[i]] = i;
		ans = max(ans, a[i]);
	}
	for (int i = 1; i <= 65; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[j][i] != -1) continue;
			if (dp[j][i - 1] == -1) continue;
			dp[j][i] = dp[dp[j][i - 1] + 1][i - 1];
			if (dp[j][i] != -1) ans = max(ans, i);
		}
	}
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}