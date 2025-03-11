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
	vector<int> dp(n + 5), psum(n + 5);
	dp[1] = psum[1] = 1;
	for (int i = 2; i <= n + 1; i++) {
		if (a[i - 1] == 0) {
			dp[i] = (psum[i - 1] - psum[max(i - k - 2, 0LL)] + MOD) % MOD;
		}
		psum[i] = (psum[i - 1] + dp[i]) % MOD;
	}
	return dp[n + 1];
}

void solve()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[++n] = 0;
	cout << (go(k) - go(k - 1) + MOD) % MOD;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}