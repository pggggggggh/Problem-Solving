#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

int dp[1005];

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 0; j < i; j++) {
			dp[i] = max(dp[i], dp[j] + a[i - j]);
		}
	}
	cout << dp[n];
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}