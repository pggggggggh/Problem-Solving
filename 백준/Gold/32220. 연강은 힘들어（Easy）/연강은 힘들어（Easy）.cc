#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

const int MOD = 1e9 + 7;

int n, k;
int a[1000005];

int go(int k)
{
	vector<int> dp(n + 1), psum(n + 1), ppsum(n + 1);
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = min(i, k);
		dp[i] = (dp[i] + ppsum[max(i - 2, 0LL)] - ppsum[max(i - 2 - k, 0LL)] + MOD) % MOD;
		psum[i] = (psum[i - 1] + dp[i]) % MOD;
		ppsum[i] = (ppsum[i - 1] + psum[i]) % MOD;
		ret = (ret + dp[i]) % MOD;
		// cout << dp[i] << ' ';
	}
	// cout << '\n';
	return ret;
}

void solve()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << (go(k) - go(k - 1) + MOD) % MOD;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}