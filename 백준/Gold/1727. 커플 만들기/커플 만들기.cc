#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1), b(m + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	if (n < m) {
		swap(n, m);
		swap(a, b);
	}
	sort(a.begin() + 1, a.end());
	sort(b.begin() + 1, b.end());
	vector dp(n + 1, vector<int>(m + 1, 1e18));
	dp[1][0] = 0;
	dp[1][1] = abs(a[1] - b[1]);
	for (int i = 2; i <= n; i++) {
		dp[i][0] = 0;
		for (int j = 1; j <= m; j++) {
			dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + abs(a[i] - b[j]));
		}
	}
	cout << dp[n][m];
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}