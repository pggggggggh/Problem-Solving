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
	vector<pi> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i].first;
	for (int i = 1; i <= n; i++) cin >> a[i].second;
	sort(all(a));
	vector dp(2, vector<int>(n + 2));
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int cur = i % 2;
		for (int j = 0; j < i; j++) {
			if (a[i].second > a[j].second)
				dp[cur][i] = max(dp[cur][i], dp[1 - cur][j] + a[i].first + a[i].second);
			dp[cur][j] = dp[1 - cur][j] + max(a[i].first, a[i].second);
		}
	}
	for (int i = 0; i <= n; i++) res = max(dp[n % 2][i], res);
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}