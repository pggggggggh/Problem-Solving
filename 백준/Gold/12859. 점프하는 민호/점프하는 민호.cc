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
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	map<int, int> dp;
	for (int i = 0; i < n; i++) {
		for (auto& [x, y] : dp) {
			int g = gcd(x, a[i]);
			if (dp.find(g) == dp.end()) {
				dp[g] = 1e18;
			}
			dp[g] = min(dp[g], dp[x] + b[i]);
		}
		if (dp.find(a[i]) == dp.end()) {
			dp[a[i]] = 1e18;
		}
		dp[a[i]] = min(dp[a[i]], b[i]);
	}
	if (dp.find(1) == dp.end()) cout << "-1";
	else cout << dp[1];
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}