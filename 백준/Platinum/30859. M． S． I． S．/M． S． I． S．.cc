#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

int dp[2][10005];

void solve()
{
	int n;
	cin >> n;
	vector<pi> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i].first;
	for (int i = 1; i <= n; i++) cin >> a[i].second;
	sort(all(a));
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i].second > a[j].second)
				dp[i & 1][i] = max(dp[i & 1][i], dp[~i & 1][j] + a[i].first + a[i].second);
			dp[i & 1][j] = dp[~i & 1][j] + max(a[i].first, a[i].second);
		}
	}
	for (int i = 0; i <= n; i++) res = max(dp[n & 1][i], res);
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}