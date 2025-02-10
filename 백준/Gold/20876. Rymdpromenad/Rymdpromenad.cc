#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

int dp[100005][301];

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(m + 1);
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
		a[i]--;
	}
	int fuck = 150;
	memset(dp, -1, sizeof(dp));
	function<int(int, int)> recur = [&](int now, int x) {
		int& ret = dp[now][x];
		if (ret != -1) return ret;
		int u = a[now] + n * x;
		if (now == m) return ret = abs(u - n * fuck);
		int lv = a[now + 1] + (x - 1) * n, rv = a[now + 1] + (x + 1) * n;
		int v = a[now + 1] + x * n;
		ret = 1e18;
		if (x > 1) ret = min(ret, recur(now + 1, x - 1) + abs(u - lv));
		ret = min(ret, recur(now + 1, x) + abs(u - v));
		if (x < 2 * fuck) ret = min(ret, recur(now + 1, x + 1) + abs(u - rv));
		return ret;
	};
	cout << recur(0, fuck);
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}