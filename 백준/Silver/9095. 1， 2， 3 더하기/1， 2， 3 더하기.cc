#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<int> dp(n + 1);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] += dp[i - 1];
		if (i - 2 >= 0) dp[i] += dp[i - 2];
		if (i - 3 >= 0) dp[i] += dp[i - 3];
	}
	cout << dp[n] << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) solve();
}