#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

const int MOD = 998244353;

int modexp(int x, int y)
{
	int res = 1;
	while (y) {
		if (y & 1) res = (res * x) % MOD;
		x = (x * x) % MOD;
		y >>= 1;
	}
	return res;
}

int dp[5005][5005];

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[2][1] = 1;
	for (int i = 3; i <= n; i++) {
		if (a[i] < a[i - 1]) {
			for (int j = 1; j < i; j++) {
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][min(j - 1, i - 2)] * modexp(2, i - j - 1) % MOD) % MOD;
			}
		} else {
			for (int j = 1; j < i; j++) {
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][min(j, i - 2)] * modexp(2, i - j - 1) % MOD) % MOD;
			}
		}
	}
	cout << dp[n][n - 1];
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}