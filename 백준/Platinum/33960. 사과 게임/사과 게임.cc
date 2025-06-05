#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

int dp[505][505];

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1), psum(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
	}
	memset(dp, -1, sizeof(dp));

	function<int(int, int)> dfs = [&](int s, int e) {
		int& ret = dp[s][e];
		if (ret != -1) return ret;

		if (psum[e] - psum[s - 1] == 10) return ret = 1;

		ret = 0;
		for (int i = s; i < e; i++) {
			ret = max(ret, dfs(s, i) + dfs(i + 1, e));
		}
		if (psum[e] - psum[s - 1] == (ret + 1) * 10) ret++;

		return ret;
	};
	cout << dfs(1, n);
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}