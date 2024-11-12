#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

map<int, vector<int>> dp;

void solve()
{
	int n, x;
	cin >> n >> x;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	function<int(int, int)> recur = [&](int now, int used) {
		if (dp.find(now) == dp.end()) dp[now] = vector<int>(n + 1, -1);
		int& ret = dp[now][used];
		if (ret != -1) return ret;
		ret = 0;
		vector<int> baesu, smaller;
		for (int i = 1; i <= n; i++) {
			int g = gcd(now, a[i]);
			if (g == 1) continue;
			if (g == now) baesu.push_back(a[i]);
			else smaller.push_back(a[i]);
		}
		for (int i = 0; i < used; i++) baesu.pop_back();
		for (auto& x : baesu) {
			if (recur(now, used + 1) == 0) return ret = 1;
		}
		for (auto& x : smaller) {
			if (recur(gcd(now, x), used + 1) == 0) return ret = 1;
		}
		return ret = 0;
	};

	cout << (recur(x, 0) ? "First" : "Second");
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}