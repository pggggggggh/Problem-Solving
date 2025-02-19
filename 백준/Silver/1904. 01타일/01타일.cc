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
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	cout << dp[n];
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}